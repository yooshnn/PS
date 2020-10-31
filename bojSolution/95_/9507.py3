import sys
input = sys.stdin.readline

dp = [0 for i in range(70)]

def fibo(n):
    if dp[n] != 0: return dp[n]
    if n<2: return 1
    if n==2: return 2
    if n==3: return 4
    dp[n] = fibo(n-1)+fibo(n-2)+fibo(n-3)+fibo(n-4)
    return dp[n]

for _ in range(int(input())):
    print(fibo(int(input())))