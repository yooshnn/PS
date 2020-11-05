import sys
input = sys.stdin.readline

W, P = map(int, input().split())
pt = [*map(int, input().split())]
res = set([W])

for i in range(P):
    res.add(W-pt[i])
    res.add(pt[i])
    for j in range(i):
        res.add(pt[i]-pt[j])

print(*sorted(res))