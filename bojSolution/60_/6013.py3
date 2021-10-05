import sys; input = sys.stdin.readline

li = []
n = int(input())
m, o = -1, (0, 0)

for i in range(n):
	li.append(tuple(map(int, input().split())))

for i in range(n-1):
	for j in range(i+1, n):
		a, b = li[i]
		c, d = li[j]
		e = abs(a-c)**2 + abs(b-d)**2
		if e>m:
			m = e
			o = (i+1, j+1)

print(*o)
