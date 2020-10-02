from sys import stdin
dp=[1]
N=int(stdin.readline())
for _ in range(1,N+1):
    dp.append(dp[_-1]*_)
fn=str(dp[N])[::-1]
res=0
for _ in fn:
    if _!="0":
        break
    res+=1
print(res)