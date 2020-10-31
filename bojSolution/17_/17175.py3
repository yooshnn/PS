import sys
input = sys.stdin.readline

n = int(input())
dp = [1, 1]

for i in range(n-1):
    dp.append((1 + dp[-1] + dp[-2])%1000000007)

print(dp[-1])
