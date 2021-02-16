import sys; input = sys.stdin.readline

MOD = 1000000009
dp = [[0 for j in range(4)] for i in range(100100)]

dp[1][1] = 1
dp[2][2] = 1
dp[3][1], dp[3][2], dp[3][3] = 1, 1, 1

for i in range(4, 100010):
    dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MOD
    dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MOD
    dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MOD

for TEST in range(int(input())):
    print(sum(dp[int(input())])%MOD)
