from sys import stdin
def input(): return stdin.readline().rstrip()

dp=[-1]*1000000

def getFail(P):
    Plen=len(P)
    ret=[0]*Plen
    j=0
    for i in range(1,Plen):
        while j>0 and P[i]!=P[j]:
            j=ret[j-1]
        if P[i]==P[j]:
            j+=1
            ret[i]=j
    return ret

def getSi(ind):
    return 1;

target=str(input())
fail=getFail(target) # List

for i in range(1,len(fail)):
    if fail[i]==0:
        continue
    if fail[i]*2==i+1:
        dp[i]=fail[i]
    elif fail[i]*2>i and dp[fail[i]-1]!=-1:
        dp[i]=dp[fail[i]-1]

for i in range(1,len(dp)):
    if dp[i]==-1: continue
    print(i+1, (i+1)//dp[i])