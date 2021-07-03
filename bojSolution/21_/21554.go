package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	rd := bufio.NewReader(os.Stdin)
	wr := bufio.NewWriter(os.Stdout)
	defer wr.Flush()

	var n int
	var arr [110]int
	var res []string

	fmt.Fscan(rd, &n)
	for i := 1; i <= n; i++ {
		fmt.Fscan(rd, &arr[i])
	}

	for i := 1; i <= n; i++ {
		if i != arr[i] {
			for j := i; j <= n; j++ {
				if i == arr[j] {
					res = append(res, strconv.Itoa(i)+" "+strconv.Itoa(j))
					for k := 0; k <= (j-i)/2; k++ {
						arr[i+k], arr[j-k] = arr[j-k], arr[i+k]
					}
					break
				}
			}
		}
	}

	fmt.Fprintln(wr, len(res))
	for i := 0; i < len(res); i++ {
		fmt.Fprintln(wr, res[i])
	}
}