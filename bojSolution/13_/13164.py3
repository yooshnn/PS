import sys; input = sys.stdin.readline

n, k = map(int, input().split())
s = [*map(int, input().split())]
t = sorted([(s[i]-s[i-1], i) for i in range(1, n)], key=lambda x: x[0], reverse=True)
u = sorted([t[i][1] for i in range(k-1)])
r = 0

tt = 0
for i in u:
    r += s[i-1]-s[tt]
    tt = i
r += s[-1]-s[tt]

print(r)
