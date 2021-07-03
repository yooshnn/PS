package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	rd := bufio.NewReader(os.Stdin); wr := bufio.NewWriter(os.Stdout); defer wr.Flush()

	var n int
	fmt.Fscan(rd, &n)

	for i:=0; i<n; i++ {
		fmt.Fprintln(wr, "SciComLove")
	}
}
