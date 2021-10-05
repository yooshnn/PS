import sys; input = sys.stdin.readline

while 1:
	a, b = map(int, input().split())
	if a==b and a==0: break
	if a>b: a, b = b, a
	print(2*a-b)