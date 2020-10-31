import sys
input = sys.stdin.readline

n = int(input())
dp = [1, 1]
for i in range(n-1):
    dp.append((dp[-1] + dp[-2]) % 10)
print(dp[-1])
