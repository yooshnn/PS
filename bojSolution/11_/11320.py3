import sys; input = sys.stdin.readline

dp = [1]
for i in range(1, 1001):
    dp.append(dp[-1] + 1 + i*2)

for TEST in range(int(input())):
    a, b = map(int, input().split())
    print(dp[a//b-1])