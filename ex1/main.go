package main

import (
	"encoding/csv"
	"fmt"
	"os"
	"time"
)

const FILENAME = "./samplefile"
const TRUE = "true"
const FALSE = "false"

type Incident struct {
	ID       string
	Team     string
	Since    time.Duration
	Severity string
	ReferTo  string
	Descr    string
}

func die(msg string, err error) {
	fmt.Fprintf(os.Stderr, "%s: %q\n", msg, err)
	os.Exit(-1)
}

func formatDuration(t time.Duration) string {
	t = t.Round(time.Second)
	h := t / time.Hour
	t -= h * time.Hour
	m := t / time.Minute
	t -= m * time.Minute
	s := t / time.Second

	return fmt.Sprintf("%dH %dm %ds", h, m, s)
}

func main() {
	fd, err := os.Open(FILENAME)
	if err != nil {
		die("while reading the file", err)
	}
	defer fd.Close()

	csvReader := csv.NewReader(fd)
	records, err := csvReader.ReadAll()
	if err != nil {
		die("while reading csv", err)
	}

	sl := make([]Incident, 0) // list of open incidents
	/*
	   I want to have a list of unique elements for impacted teams and
	   security levels reached..
	   The slice is not the way because there is no builtin to identify
	   unique elements..
	   Maps allow to do that easily with:
	   map[uniq_element] = nil
	   for key, _ := range map
	*/
	teams := make(map[string]interface{}, 0)
	sev := make(map[string]interface{}, 0)
	for _, v := range records {
		if v[4] == TRUE { // we have an open incident
			// also `go doc time.Layout` but this is no default I guess..
			incDur, err := time.Parse("2006-01-02 15:04:05 +0000 UTC", v[2])
			if err != nil {
				die("while converting time", err)
			}
			currT := time.Now()
			elapsed := currT.Sub(incDur)

			teams[v[5]] = nil
			sev[v[3]] = nil

			sl = append(sl, Incident{
				Team:     v[5],
				ID:       v[0],
				Since:    elapsed,
				Severity: v[3],
				ReferTo:  v[6],
				Descr:    v[1],
			})
		}
	}

	// ================= OUT
	for _, v := range sl {
		fmt.Printf("Open Incident:\n")
		fmt.Printf("\tID: %s\n", v.ID)
		fmt.Printf("\tDuration: %s\n", formatDuration(v.Since))
		fmt.Printf("\tTeam: %s\n", v.Team)
		fmt.Printf("\tSeverity: %s\n", v.Severity)
		fmt.Printf("\tRefer: %s\n", v.ReferTo)
		fmt.Printf("\tDescr: %s\n", v.Descr)
		fmt.Println()
	}

	fmt.Printf("\nAftermath =====================================\n")
	fmt.Printf("Total Incidents: %d\n", len(sl))
	fmt.Printf("Teams Impacted:\n")
	for k := range teams {
		fmt.Printf("\t- %s\n", k)
	}
	fmt.Printf("Severity levels:\n")
	for k := range sev {
		fmt.Printf("\t- %s\n", k)
	}
}
