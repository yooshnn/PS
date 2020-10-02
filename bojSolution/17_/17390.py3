from sys import stdin
input = stdin.readline

N, Q = map(int, input().split())
sraw = sorted(map(int, input().split()))
s = [0 for i in range(N)]
s[0] = sraw[0]
for i in range(1, N):
    s[i] = s[i-1]+sraw[i]
for q in range(Q):
    l, r = map(int, input().split())
    if l == 1: print(s[r-1])
    else: print(s[r-1]-s[l-2])