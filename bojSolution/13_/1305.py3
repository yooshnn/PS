from sys import stdin

def getFail(ps):
    ret=[0]*L
    j=0
    for i in range(1,L):
        while j>0 and P[i]!=P[j]:
            j=ret[j-1]
        if P[i]==P[j]:
            j+=1
            ret[i]=j
    return ret

L=int(stdin.readline()) # 광고판 길이
P=str(stdin.readline()[:-1])

fail=L-getFail(P)[L-1]
print(fail)