import sys; input = sys.stdin.readline

n, p = map(int, input().split())
pt = [int(input()) for i in range(n)]
res = []

t = 0 if pt[n-1]==0 else 1
res.append(t)

for i in range(n-2, -1, -1):
    if pt[i]>pt[i+1] or pt[i]!=0 and pt[i+1]==0:
        t += 1
    res.append(t)

if res[-1]==p or res[-1]==0:
    print(*res[::-1], sep="\n")
else:
    print("ambiguous")