import sys; input = sys.stdin.readline

res = 0
n, m = map(int, input().split())

for i in range(1, n+1):
    t = str(i)
    res += t.count(str(m))

print(res)
