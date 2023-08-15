package main

import "testing"

func TestPeakIndexInMountainArray(t *testing.T) {
	cases := []struct {
		inpt   []int
		expctd int
	}{
		{[]int{0, 1, 0}, 1},
		{[]int{0, 2, 1, 0}, 1},
		{[]int{0, 10, 5, 2}, 1},
		{[]int{3, 4, 5, 1}, 2},
		{[]int{40, 48, 61, 75, 100, 99, 98, 39, 30, 10}, 4},
		{[]int{24, 69, 100, 99, 79, 78, 67, 36, 26, 19}, 2},
		{[]int{18, 29, 38, 59, 98, 100, 99, 98, 90}, 5},
		{[]int{12, 13, 19, 41, 55, 69, 70, 71, 96, 72}, 8},
	}

	for _, c := range cases {
		t.Logf("Trying: %v\n", c.inpt)
		indx := PeakIndexInMountainArray(c.inpt)
		if indx != c.expctd {
			t.Fatalf("Expected %d, got %d", c.expctd, indx)
		}
	}
}
