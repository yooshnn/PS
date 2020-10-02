from sys import stdin
from collections import deque
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

def KMP():
    Tlen=len(target);
    Plen=len(ref)
    dp=[0]*Tlen
    ptr=0
    j=0
    for i in range(Tlen):
        while j>0 and target[i]!=ref[j]:
            j=fail[j-1]
        if target[i]==ref[j]:
            j+=1
        res[ptr]=target[i]
        dp[ptr]=j
        if j==Plen:
            ptr-=Plen
            j=dp[ptr]
        ptr+=1
    return ptr

while 1:
    caseInfo=input().split()
    if not caseInfo: break

    l,ref=int(caseInfo[0]),str(caseInfo[1])
    fail=getFail(ref) # List

    target=""

    for _ in range(l):
        target=input()

        res=[""]*len(target)
        reslen=KMP()
        print("".join(res[:reslen]))