import sys; input = sys.stdin.readline

n, x, k = map(int, input().split())
s = [0 for i in range(n+1)]
s[x] = 1
for i in range(k):
    p, q = map(int, input().split())
    s[p] ^= s[q]
    s[q] ^= s[p]
    s[p] ^= s[q]
for i in range(n+1):
    if s[i]==1: print(i)