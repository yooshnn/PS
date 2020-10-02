from sys import stdin
def input(): return stdin.readline().rstrip()
dp=[[0 for j in range(101)] for i in range(101)]
dps=[["" for j in range(101)] for i in range(101)]
a=[]
b=[]
while 1:
    escape=False
    dp=[[0 for j in range(101)] for i in range(101)]
    dps=[["" for j in range(101)] for i in range(101)]
    del a[:]
    del b[:]
    while 1:
        line=input()
        if not line:
            escape = True
            break
        line=line.split()
        if line[0]=='#': break
        for i in line:
            a.append(i)
    if escape==True:
        break
    while 1:
        line=input().split()
        if line[0]=='#': break
        for i in line:
            b.append(i)

    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            if a[i-1]==b[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
                dps[i][j]=dps[i-1][j-1]+" "+a[i-1]
            else:
                if dp[i-1][j]>dp[i][j-1]:
                    dp[i][j]=dp[i-1][j]
                    dps[i][j]=dps[i-1][j]
                else:
                    dp[i][j]=dp[i][j-1]
                    dps[i][j]=dps[i][j-1]

    print(dps[len(a)][len(b)].lstrip())
