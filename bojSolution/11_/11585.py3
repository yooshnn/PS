from sys import stdin
from math import gcd
def input(): return stdin.readline().rstrip()

def getFail(ps):
    ret=[0]*Plen
    j=0
    for i in range(1,Plen):
        while j>0 and P[i]!=P[j]:
            j=ret[j-1]
        if P[i]==P[j]:
            j+=1
            ret[i]=j
    return ret

def KMP(T, P):
    ret=0
    j=0
    for i in range(Tlen):
        while j>0 and T[i]!=P[j]:
            j=fail[j-1]
        if T[i]==P[j]:
            if j==Plen-1:
                ret+=1
                j=fail[j]
            else:
                j+=1
    return ret

N=int(input())
T=str(input().replace(" ",""))
P=str(input().replace(" ",""))
T=T+T[:-1]
Tlen=len(T)
Plen=len(P)
fail=getFail(P) # List
res=KMP(T,P)
print(res//gcd(res,N),'/',N//gcd(res,N),sep="")