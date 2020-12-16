import sys; input = sys.stdin.readline

d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def solve(n: int, b: int):
    p, q = divmod(n, b)
    if p==0: return d[q]
    return solve(p, b) + d[q]

n, b = map(int, input().split())
print(solve(n, b))