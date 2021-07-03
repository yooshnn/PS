package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a int64, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	rd := bufio.NewReader(os.Stdin)
	wr := bufio.NewWriter(os.Stdout)
	defer wr.Flush()

	var n int
	var k int64
	var cost, dp [200010][2]int64

	fmt.Fscan(rd, &n, &k)
	for j := 0; j < 2; j++ {
		for i := 0; i < n; i++ {
			fmt.Fscan(rd, &cost[i][j])
		}
	}

	dp[0][0] = cost[0][0]
	dp[0][1] = cost[0][1]
	for i := 1; i < n; i++ {
		dp[i][0] = cost[i][0] + min(dp[i-1][0], dp[i-1][1]+k)
		dp[i][1] = cost[i][1] + min(dp[i-1][0]+k, dp[i-1][1])
	}

	fmt.Fprint(wr, min(dp[n-1][0], dp[n-1][1]))

}