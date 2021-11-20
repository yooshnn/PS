import sys; input = sys.stdin.readline

res = 0
n = input().rstrip()
for i in n:
	res += int(i)**5
print(res)
