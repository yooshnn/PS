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

while True:
    P=str(stdin.readline()[:-1])
    if P==".":
        break
    Plen=len(P)

    fail=Plen-getFail(P)[Plen-1] # List
    if Plen%fail == 0:
        print(Plen//(fail))
    else:
        print(1)