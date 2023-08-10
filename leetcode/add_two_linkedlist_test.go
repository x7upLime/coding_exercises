package main

import (
	"slices"
	"testing"
)

func GenerateLL(digits []int) *ListNode {
	slices.Reverse(digits)
	var lastNode *ListNode
	for _, v := range digits {
		lst := ListNode{
			Val:  v,
			Next: lastNode,
		}

		lastNode = &lst
	}
	return lastNode
}

func LLToNum(ll *ListNode) int {
	sm := 0
	mltplr := 1
	for {
		sm += ll.Val * mltplr
		if ll.Next == nil {
			break
		}
		ll = ll.Next
		mltplr = mltplr * 10
	}

	return sm
}

func TestAddTwoNumbers(t *testing.T) {
	cases := []struct {
		inpt1  *ListNode
		inpt2  *ListNode
		expctd *ListNode
	}{
		{inpt1: GenerateLL([]int{2, 4, 3}), inpt2: GenerateLL([]int{5, 6, 4}), expctd: GenerateLL([]int{7, 0, 8})},
		{inpt1: GenerateLL([]int{0}), inpt2: GenerateLL([]int{0}), expctd: GenerateLL([]int{0})},
		{inpt1: GenerateLL([]int{9, 9, 9, 9, 9, 9, 9}), inpt2: GenerateLL([]int{9, 9, 9, 9}), expctd: GenerateLL([]int{8, 9, 9, 9, 0, 0, 0, 1})},
	}

	for _, c := range cases {
		res := AddTwoNumbers(c.inpt1, c.inpt2)
		nres, nexpctd := LLToNum(res), LLToNum(c.expctd)
		if nres != nexpctd {
			t.Fatalf("We've got %d while expecting %d\n", nres, nexpctd)
		}
	}
}
