package main

func PeakIndexInMountainArray(arr []int) int {
	ln := func(arr []int) int {
		return len(arr)/2 + ((len(arr) % 2) - 1)
	}
	l1 := ln(arr)
	l2 := l1 + 1
	ll1, ll2 := 0, len(arr)
	var off int
	for {
		if arr[l1] > arr[l2] {
			ll1, ll2 = off, l1+1

			l1 = ln(arr[ll1:ll2]) + off
			l2 = l1 + 1
		} else {
			ll1, ll2 = l2, ll2

			off = l2

			l1 = ln(arr[ll1:ll2]) + off
			l2 = l1 + 1
		}

		if len(arr[ll1:ll2]) == 2 || ll2-ll1 == 1 {
			if arr[l1] > arr[l2] {
				return l1
			} else {
				return l2
			}
		}
	}
}

// func main() {
// 	// arr := []int{0, 1, 0}
// 	// arr := []int{0, 2, 1, 0}
// 	// arr := []int{40, 48, 61, 75, 100, 99, 98, 39, 30, 10}
// 	arr := []int{24, 69, 100, 99, 79, 78, 67, 36, 26, 19}
// 	// arr := []int{3, 4, 5, 1}
// 	// arr := []int{18, 29, 38, 59, 98, 100, 99, 98, 90}
// 	// arr := []int{12, 13, 19, 41, 55, 69, 70, 71, 96, 72}
// 	indx := PeakIndexInMountainArray(arr)
// 	fmt.Printf("We got index: %d, which is %d\n", indx, arr[indx])
// }
