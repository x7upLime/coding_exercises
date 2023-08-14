package main

func RemoveElement(nums []int, val int) int {
	l := len(nums) - 1
	var cntr int
	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			nums[i] = nums[l] // last elem overwrites curr
			nums = nums[:l]   // erase last elem

			i -= 1
			l -= 1
		} else {
			cntr += 1
		}
	}

	return cntr
}

// func main() {
// 	nums := []int{0, 1, 2, 2, 3, 0, 4, 2}
// 	dontwant := 2
// 	rrr := RemoveElement(nums, dontwant)

// 	fmt.Printf("We have %v\nLength: %d\n", nums, rrr)
// }
