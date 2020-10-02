from sys import stdin
def input(): return stdin.readline().rstrip()

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

tc=0
while 1:
    tc+=1
    L=int(input())
    if L==0: break

    dp=[-1]*L
    target=str(input())
    fail=getFail(target) # List

    for i in range(1,L):
        if fail[i]==0:
            continue
        if fail[i]*2==i+1:
            dp[i]=fail[i]
        elif fail[i]*2>i and dp[fail[i]-1]!=-1:
            dp[i]=dp[fail[i]-1]

    print("Test case #{}".format(tc))
    for i in range(1,L):
        if dp[i]==-1: continue
        print(i+1, (i+1)//dp[i])
    print()