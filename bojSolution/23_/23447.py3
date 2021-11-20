import sys; input = sys.stdin.readline

for TEST in range(1, int(input())+1):
	print("Case #%d:\nYES"%TEST)
	n = int(input())
	for x in range(1, n+1):
		for y in range(1, x+1):
			print(y, x, y, x, 1, y, x, 2)