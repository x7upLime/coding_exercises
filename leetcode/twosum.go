package main

func TwoSum(nums []int, target int) []int {
	for i, n := range nums {
		for j, nn := range nums {
			if i == j {
				continue
			}

			if n+nn == target {
				return []int{i, j}
			}
		}
	}

	return nil
}
