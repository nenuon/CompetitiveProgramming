package main

import (
	"fmt"
)

func main() {
	var N, M, C int
	fmt.Scan(&N, &M, &C)
	B := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&B[i])
	}
	A := make([][]int, N)
	for i := 0; i < N; i++ {
		A[i] = make([]int, M)
		for j := 0; j < M; j++ {
			fmt.Scan(&A[i][j])
		}
	}
	ret := 0
	for i := 0; i < N; i++ {
		sum := 0
		for j := 0; j < M; j++ {
			sum += B[j] * A[i][j]
		}
		if sum+C > 0 {
			ret++
		}
	}
	fmt.Println(ret)
}
