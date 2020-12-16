import sys
input = sys.stdin.readline

def solve(n):
    global P, Q
    try:
        ret = dp[n]
        return ret
    except:
        a, b = solve(n//P), solve(n//Q)
        dp[n//P], dp[n//Q] = a, b
        return a+b

dp = {}
dp[0] = 1
N, P, Q = map(int, input().split())

print(solve(N))