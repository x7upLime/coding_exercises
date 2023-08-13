package main

import (
	"math/big"
)

func ClimbStairs(n int64) int {
	req2s := int64(n / 2)
	req1s := int64(n)

	sm := big.NewInt(1)
	var cmbs *big.Int
	for cntr1, cntr2 := int64(req1s-2), int64(1); cntr2 <= req2s && cntr1 >= 0; cntr1, cntr2 = cntr1-2, cntr2+1 {
		dn := (big.NewInt(0).Mul(Factorial(cntr1), Factorial(cntr2)))
		up := Factorial(cntr1 + cntr2)
		cmbs = (big.NewInt(0).Div(up, dn))
		sm = big.NewInt(0).Add(sm, cmbs)
	}

	return int(sm.Int64())
}

func Factorial(n int64) (res *big.Int) {
	if n == 0 || n == 1 {
		return big.NewInt(1)
	} else {
		return big.NewInt(0).Mul(big.NewInt(n), Factorial(n-1))
	}
}
