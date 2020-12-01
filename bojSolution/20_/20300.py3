import sys
input = sys.stdin.readline

n = int(input())
t = sorted([*map(int, input().split())])
r = 0

if n&1:
    for i in range(n//2):
        r = max(r, t[i]+t[n-2-i])
    r = max(r, t[-1])
    print(r)
else:
    for i in range(n//2):
        r = max(r, t[i]+t[n-1-i])
    print(r)