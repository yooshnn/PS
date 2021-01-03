import sys; input = sys.stdin.readline

d = "0123456789ABCDEF"

def solve(num, base):
    q, r = divmod(num, base)
    n = d[r]
    return solve(q, base) + n if q else n

m, n = map(int, input().split())
print(solve(m, n))
