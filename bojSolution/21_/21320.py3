import sys; input = sys.stdin.readline

n, k = map(int, input().split())
dp = [0, 0]

for i in range(n):
    dp.append(dp[-1]*2)
    if ~i&1: dp[-1] += 2
    dp[-1] %= 1000000007

res = dp[n-1]
if n&1: res += 1 - (k&1)
else: res += k&1
res %= 1000000007

print(res)