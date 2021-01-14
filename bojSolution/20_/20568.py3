import sys; input = sys.stdin.readline

n = int(input())
s = sorted([*map(int, input().split())])
cry = 0

for i in range(1, n):
    if s[i-1]>=s[i]: cry += 1

print(cry)
