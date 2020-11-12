import sys
input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
total = sum(s)
res = 0

for i in range(n):
    total -= s[i]
    res += s[i] * total

print(res)