import sys; input = sys.stdin.readline

n, p = map(int, input().split())
cnt = [0 for i in range(p+1)]

for i in range(n):
    li = [*map(int, input().split())]
    m, M = min(li), max(li)
    for j in range(p):
        if li[j] == m: cnt[j+1] += 1
        if li[j] == M: cnt[j+1] = -10000

f = True
for i in range(1, p+1):
    if cnt[i] > n//2:
        f = False
        print(i)
if f: print(0)