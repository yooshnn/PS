import sys; input = sys.stdin.readline

d = "0123456789"

def solve(n, b):
    q, r = divmod(n, b)
    x = d[r]
    return solve(q, b) + x if q else x

print(solve(int(input()), 9))
