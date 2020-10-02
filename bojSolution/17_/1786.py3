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
    ret=[]
    j=0
    for i in range(Tlen):
        while j>0 and T[i]!=P[j]:
            j=fail[j-1]
        if T[i]==P[j]:
            if j==Plen-1:
                ret.append(str(i-Plen+2))
                j=fail[j]
            else:
                j+=1
    return ret

T=str(stdin.readline()[:-1])
P=str(stdin.readline()[:-1])
Tlen=len(T)
Plen=len(P)
fail=getFail(P) # List
res=KMP(T,P)
print(len(res))
print(" ".join(res))