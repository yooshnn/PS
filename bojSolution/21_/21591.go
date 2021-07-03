package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int
	fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)

	if a >= c+2 && b >= d+2 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}