import sys; input = sys.stdin.readline

l = []

N = int(input())
for _ in range(N):
    p, q = input().split()
    l.append((int(p), int(q)))
l.sort()

orp = l[0][1]
res = l[0][1] - l[0][0]

for i in range(1, N):
    if l[i][1]>orp:
        res += l[i][1] - l[i][0]
        res += min(0, l[i][0] - orp)
        orp = l[i][1]

print(res)