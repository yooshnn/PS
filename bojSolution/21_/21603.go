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

	var n, k int
	var res []int
	fmt.Fscan(rd, &n, &k)

	for i := 1; i <= n; i++ {
		if i%10 != k%10 && i%10 != (2*k)%10 {
			res = append(res, i)
		}
	}

	fmt.Fprintln(wr, len(res))
	for i := 0; i < len(res); i++ {
		fmt.Fprint(wr, res[i])
        fmt.Fprint(wr, " ")
	}
}