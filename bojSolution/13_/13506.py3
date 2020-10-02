from sys import stdin

def getFail(ps):
    ret=[0]*len(P)
    j=0
    for i in range(1,len(P)):
        while j>0 and P[i]!=P[j]:
            j=ret[j-1]
        if P[i]==P[j]:
            j+=1
            ret[i]=j
    return ret

def KMP(t, p):
    Tlen=len(t)
    Plen=len(p)
    ret=[]
    j=0
    for i in range(Tlen):
        while j>0 and t[i]!=p[j]:
            j=fail[j-1]
        if t[i]==p[j]:
            if j==Plen-1:
                ret.append(str(i-Plen+2))
                j=fail[j]
            else:
                j+=1
    return ret

T=str(input().rstrip())
P=T
fail=getFail(P)

f=fail[-1]
res=0
flag=False
while f>0:
    if len(KMP(T[1:-1],T[:f]))==0:
        f=fail[f-1]
    else:
        res=f
        flag=True
        break
if flag==1:
    print(T[:f])
else:
    print(-1)
