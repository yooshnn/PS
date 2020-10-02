from sys import stdin
def input(): return stdin.readline().rstrip()

res = 0
for _ in range(int(input())):
    n, m = map(int, input().split())
    r = 0
    while n*r <= m:
        r += 1
    r -= 1
    res += (m - n*r)

print(res)