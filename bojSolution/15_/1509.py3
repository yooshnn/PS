from sys import stdin

s=stdin.readline().strip()
slen=len(s)

pal=[[False for j in range(slen)] for i in range(slen)]

for i in range(slen):
    pal[i][i]=True
    if i==slen-1: continue
    pal[i][i+1]=(s[i]==s[i+1])

for i in range(2,slen):
    for j in range(slen-i):
        if pal[j+1][j+i-1] and s[j]==s[j+i]:
            pal[j][j+i]=True

dp=[0]*slen
dp[0]=1
for i in range(1,slen):
    dp[i]=dp[i-1]+1
    for j in range(i):
        if s[j]==s[i]:
            if i==1 or (j==0 and pal[0][i]):
                dp[i]=1
            else:
                if pal[j][i]:
                    dp[i]=min(dp[i], dp[j-1]+1)

print(dp[slen-1])