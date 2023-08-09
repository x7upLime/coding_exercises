package main

import (
	"reflect"
	"testing"
)

func TestTwoSum(t *testing.T) {
	cases := []struct {
		input  []int
		tgt    int
		expctd []int
	}{
		{[]int{2, 7, 11, 5}, 9, []int{0, 1}},
		{[]int{3, 2, 4}, 6, []int{1, 2}},
		{[]int{3, 3}, 6, []int{0, 1}},
	}

	for _, c := range cases {
		res := TwoSum(c.input, c.tgt)
		if !reflect.DeepEqual(res, c.expctd) {
			t.Fatalf("result for %v and %v is %v. Expected %v\n", c.input, c.tgt, res, c.expctd)
		}
	}
}
