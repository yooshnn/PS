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
	var board [110][110]int
	var dp [110][110]int64

	fmt.Fscan(rd, &n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Fscan(rd, &board[i][j])
		}
	}

	dp[0][0] = 1
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == 0 {
				continue
			}
			if i+board[i][j] < n {
				dp[i+board[i][j]][j] += dp[i][j]
			}
			if j+board[i][j] < n {
				dp[i][j+board[i][j]] += dp[i][j]
			}
		}
	}
    
	fmt.Fprint(wr, dp[n-1][n-1])
    
}