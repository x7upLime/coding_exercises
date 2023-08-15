package main

import (
	"fmt"
	"slices"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func walkLL(lst *ListNode) {
	for {
		fmt.Printf("%d\n", lst.Val)
		if lst.Next == nil {
			return
		}
		lst = lst.Next
	}
}

func AddTwoNumbers(l1, l2 *ListNode) *ListNode {
	head := &ListNode{0, nil}
	tail := head
	dec := 0
	for {
		sm := l1.Val + l2.Val + dec
		dec = sm / 10
		unt := sm % 10

		tail.Next = &ListNode{unt, nil}

		if l1.Next == nil && l2.Next == nil {
			if dec != 0 {
				tail.Next.Next = &ListNode{dec, nil}
			}
			break
		}

		if l1.Next == nil {
			l1.Val = 0
		} else {
			l1 = l1.Next
		}

		if l2.Next == nil {
			l2.Val = 0
		} else {
			l2 = l2.Next
		}

		tail = tail.Next
	}

	return head.Next
}

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

func debug() {
	l1 := GenerateLL([]int{9, 9, 9, 9, 9, 9, 9})
	l2 := GenerateLL([]int{9, 9, 9, 9})

	l3 := AddTwoNumbers(l1, l2)
	walkLL(l3)
}
