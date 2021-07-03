package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	bufin  = bufio.NewReader(os.Stdin)
	bufout = bufio.NewWriter(os.Stdout)
)

func printf(f string, a ...interface{}) { fmt.Fprintf(bufout, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(bufin, f, a...) }

func main() {
	defer bufout.Flush()

	var t1, v1, t2, v2 int

	scanf("%d %d\n%d %d", &t1, &v1, &t2, &v2)

	if t2 < 0 && v2 >= 10 {
		printf("A storm warning for tomorrow! Be careful and stay home if possible!")
	} else if t2 < t1 {
		printf("MCHS warns! Low temperature is expected tomorrow.")
	} else if v2 > v1 {
		printf("MCHS warns! Strong wind is expected tomorrow.")
	} else {
		printf("No message")
	}
}