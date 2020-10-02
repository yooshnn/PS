from sys import stdin

def getFail(ps):
    ret=[0]*len(ps)
    j=0
    for i in range(1,len(ps)):
        while j>0 and ps[i]!=ps[j]:
            j=ret[j-1]
        if ps[i]==ps[j]:
            j+=1
            ret[i]=j
    return ret

P=str(stdin.readline()[:-1])
Plen=len(P)
fail=0

for i in range(Plen):
    fail=max(fail,sorted(getFail(P[i:]))[-1]) # List

print(fail)
