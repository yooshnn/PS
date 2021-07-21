import sys; input = sys.stdin.readline

d, m = map(int, input().split())
d = (d // 2) - 1

dp = [0 for i in range(4020)]
dp[0] = 1

for i in range(1, 2010):
    for j in range(i):
        dp[i] += dp[j] * dp[i-1-j]
        dp[i] %= m

print(dp[d])