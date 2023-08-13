package main

import (
	"testing"
)

func TestClimbStairs(t *testing.T) {
	cases := []struct {
		inpt  int64
		outpt int
	}{
		{2, 2},
		{3, 3},
		{1, 1},
		{4, 5},
		{35, 14930352},
	}

	for _, c := range cases {
		res := ClimbStairs(c.inpt)
		if res != c.outpt {
			t.Fatalf("Expected %d, had %d\n", c.outpt, res)
		}
	}
}
