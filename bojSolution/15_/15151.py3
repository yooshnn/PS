import sys; input = sys.stdin.readline

n, k = map(int, input().split())
r = 0

while k >= n:
    r += 1
    k -= n
    n *= 2

print(r)
