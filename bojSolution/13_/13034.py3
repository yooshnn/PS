import sys; input = sys.stdin.readline

n = int(input())
dp = [0,0,1]

for i in range(3, n+1):
    next = set()
    for j in range((i-2)//2+1):
        next.add(dp[j]^dp[i-2-j])
    tt = 0
    while tt in next:
        tt += 1
    dp.append(tt)

print(2 if dp[n]==0 else 1)
