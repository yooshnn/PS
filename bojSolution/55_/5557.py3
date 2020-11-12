import sys
input = sys.stdin.readline

dp = [[0 for i in range(21)] for j in range(101)]

n = int(input())
s = [*map(int, input().split())]

dp[0][s[0]] = 1

for i, c in enumerate(s):
    if i==0: continue
    for j in range(21):
        if j-c >= 0: dp[i][j] += dp[i-1][j-c]
        if j+c <= 20: dp[i][j] += dp[i-1][j+c]
print(dp[n-2][s[-1]])
