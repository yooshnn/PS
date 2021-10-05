import sys; input = sys.stdin.readline

TEST = 0
while 1:
	TEST += 1
	n = int(input())
	if n==0: break

	res = 0
	li = [*map(int, input().split())]
	t = sum(li)//n

	for i in li:
		res += max(0, i-t)

	print("Set #%d\nThe minimum number of moves is %d.\n"%(TEST, res))
