package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func AddTwoNumbers(l1, l2 *ListNode) *ListNode {
	var firstNode *ListNode
	var lastNode *ListNode
	var prevNode *ListNode
	dec := 0
	for {
		sm := l1.Val + l2.Val + dec
		dec = sm / 10
		unt := sm % 10

		lastNode = &ListNode{Val: unt}
		if prevNode != nil {
			prevNode.Next = lastNode
		}
		if firstNode == nil {
			firstNode = lastNode
		}

		if l1.Next == nil && l2.Next == nil {
			if dec != 0 {
				lastNode.Next = &ListNode{dec, nil}
			}
			break
		}

		if l1.Next == nil {
			l1 = &ListNode{Val: 0, Next: nil}
		} else {
			l1 = l1.Next
		}

		if l2.Next == nil {
			l2 = &ListNode{Val: 0, Next: nil}
		} else {
			l2 = l2.Next
		}

		prevNode = lastNode
	}

	return firstNode
}
