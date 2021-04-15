from sys import stdin
n = int(stdin.readline())
s = [int(x) for x in stdin.readline().split()]
dp = [1]*1001
dp[0] = 1

res = 1
for i in range(n):
    for j in range(i):
        if s[i]>s[j] and dp[i]<=dp[j]:
            dp[i] = max(dp[i],dp[j] + 1)
            if dp[i] > res:
                res = dp[i]

print(res)