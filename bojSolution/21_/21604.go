package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	rd := bufio.NewReader(os.Stdin); wr := bufio.NewWriter(os.Stdout); defer wr.Flush()

	var n, m int
	var t [1010][1010]int
	fmt.Fscan(rd, &n, &m)

	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			fmt.Fscan(rd, &t[i][j])
		}
	}

	fmt.Fprintln(wr, m)
	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			fmt.Fprint(wr, t[(i+j)%m][j])
			fmt.Fprint(wr, " ")
		}
		fmt.Fprintln(wr)
	}
}