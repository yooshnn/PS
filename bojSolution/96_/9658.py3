N=int(input())
dp=[1]*1020
dp[:5]=[0,0,1,0,1]
for i in range(5,N+5):
    if dp[i-1]+dp[i-3]+dp[i-4]==3:
        dp[i]=0
print(["CY","SK"][dp[N]])