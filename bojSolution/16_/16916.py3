from sys import stdin

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
    j=0
    for i in range(Tlen):
        while j>0 and T[i]!=P[j]:
            j=fail[j-1]
        if T[i]==P[j]:
            if j==Plen-1:
                return 1;
            else:
                j+=1
    return 0

T=str(stdin.readline().strip())
P=str(stdin.readline().strip())

Tlen=len(T)
Plen=len(P)

fail=getFail(P) # List

res=KMP(T,P)

print(res)
