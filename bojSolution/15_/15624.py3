import sys
input = sys.stdin.readline

n = int(input())
dp = [0, 1]
for i in range(n-1):
    dp.append((dp[-1] + dp[-2])%1000000007)
if n == 0:
    print(0)
else:
    print(dp[-1])