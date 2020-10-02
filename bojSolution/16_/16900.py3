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
    return ret[Plen-1]

x,y=stdin.readline().split()
P=str(x)
y=int(y)
Plen=len(P)

fail=getFail(P)
print((Plen-fail)*(y-1)+Plen)