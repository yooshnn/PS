from sys import stdin
def input(): return stdin.readline().rstrip()
INF=1000000000

dp=[-1]*1000000
fail=[]
res=0

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

def minFail(ind):
    if fail[ind]==0:
        return INF
    if dp[ind]!=-1:
        return dp[ind]
    dp[ind]=min(fail[ind],minFail(fail[ind]-1))
    return dp[ind]

L=int(input())
target=str(input())
fail=getFail(target)

for i in range(L):
    get=minFail(i)
    if get==INF: continue
    res+=(1+i)-get

print(res)