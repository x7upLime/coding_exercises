package main

func TwoSum(nums []int, target int) []int {
	nnn := make(map[int]int) // a nums/index map
	for i := 0; i < len(nums); i++ {
		if nn, ok := nnn[target-nums[i]]; ok {
			return []int{nn, i}
		}
		nnn[nums[i]] = i
	}

	return nil
	// Best solution in speed.. consumes more memory than the following tho O.o
	// Alternative:
	/*
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

	*/
}
