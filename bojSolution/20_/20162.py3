import sys
input = sys.stdin.readline

n = int(input())
s = [int(input()) for x in range(n)]
dp = [s[i] for i in range(n)]

for i in range(n):
    for j in range(i):
        if s[i]>s[j]:
            dp[i] = max(dp[i], dp[j] + s[i])

print(max(dp))