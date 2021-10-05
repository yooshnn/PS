import sys; input = sys.stdin.readline

n = int(input())

dp = [0, 1, 1, 3]
for i in range(4, 62):
    dp.append(dp[-2] + 2**(i-2))

print(dp[n+1])