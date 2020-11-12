import sys
input = sys.stdin.readline

dp = [1, 1]
w = 1
for i in range(2,1020):
    w *= i
    while w%10 == 0:
        w//=10
    w %= 10000000000000
    dp.append((w)%10)

for _ in range(int(input())):
    n = int(input())
    print(dp[n])
