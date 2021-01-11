import sys; input = sys.stdin.readline

m, n = map(int, input().split())
r = [0 for x in range(10)]
for i in range(m, n+1):
    for c in str(i):
        r[ord(c)-ord("0")] += 1
print(*r)
