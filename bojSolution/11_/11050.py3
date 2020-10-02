from sys import stdin
dp=[1,1]
N,K=map(int,stdin.readline().split())
for i in range(2,N+1):
    dp.append(dp[i-1]*i)
print(dp[N]//(dp[N-K]*dp[K]))