import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = map(int, input().split())
r = [0 for i in range(1001)]

for c in s:
    r[c] += 1

print(max(r))