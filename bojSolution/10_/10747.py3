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

def KMP(T, P):
    Tlen=len(T); Plen=len(P)
    ret=[""]*Tlen
    ptr=0
    j=0
    for i in range(Tlen):
        while j>0 and T[i]!=P[j]:
            j=fail[j-1]
        if T[i]==P[j]:
            j+=1
        ret[ptr]=T[i]
        dp[ptr]=j
        if j==Plen:
            ptr-=Plen
            j=dp[ptr]
        ptr+=1
    return ret[:ptr]

S=str(input())
T=str(input())
fail=getFail(T) # List
dp=[0]*len(S)
print("".join(KMP(S,T)))