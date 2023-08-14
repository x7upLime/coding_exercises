package main

import (
	"sort"
	"testing"
)

func TestRemoveElement(t *testing.T) {
	cases := []struct {
		inptNums  []int
		inptVal   int
		outExpctd []int
	}{
		{[]int{3, 2, 2, 3}, 3, []int{2, 2}},
		{[]int{0, 1, 2, 2, 3, 0, 4, 2}, 2, []int{0, 1, 4, 0, 3}},
	}

	for _, c := range cases {
		out := RemoveElement(c.inptNums, c.inptVal)
		sort.Ints(c.inptNums)
		sort.Ints(c.outExpctd)
		if out != len(c.outExpctd) {
			t.Fatalf("Len expected: %d, got %d\n", len(c.outExpctd), out)
		}

	}
}

// checkSlices check if all the elements are equal in the same order,
// len is the length of the expected output
func checkSlices(sl1, sl2 []int, len int) bool {
	for i := 0; i < len; i++ {
		if sl1[i] != sl2[i] {
			return false
		}
	}

	return true
}
