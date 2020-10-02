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
    Tlen,Plen=len(T),len(P)
    j=0
    for i in range(Tlen):
        while j>0 and T[i]!=P[j]:
            j=fail[j-1]
        if T[i]==P[j]:
            if j==Plen-1:
                return 1
                j=fail[j]
            else:
                j+=1
    return 0

n=int(input())
_c1=list(map(int,input().split()))
_c2=list(map(int,input().split()))
c1=[0]*360000
c2=[0]*360000
for i in _c1:
    c1[i]=1
for i in _c2:
    c2[i]=1
c1=c1+c1[:-1]
fail=getFail(c2)
print(["impossible","possible"][KMP(c1,c2)])