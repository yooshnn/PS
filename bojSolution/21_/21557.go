package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	rd := bufio.NewReader(os.Stdin)
	wr := bufio.NewWriter(os.Stdout)
	defer wr.Flush()

	var n int
	var l, r int

	fmt.Fscan(rd, &n)
	fmt.Fscan(rd, &l)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(rd, &r)
	}

	for i := 0; i < n-3; i++ {
		if l > r {
			l -= 1
		} else {
			r -= 1
		}
	}

	if l > r {
		fmt.Fprint(wr, l-1)
	} else {
		fmt.Fprint(wr, r-1)
	}
}