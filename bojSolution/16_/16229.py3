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

N,K=map(int,input().split())
S=input()

fail=getFail(S)

if N<=K:
    print(N)
else:
    res=0
    f=fail[-1] # f[f[i]-1]로 모든 fail함수 값을 구할 수 있다
    while f>0:
        pl=len(S)-f # 패턴길이
        po=(N-1)//pl+1 # occurrence
        if N<=pl*po and pl*po<=N+K:
            res=max(res,pl)
        f=fail[f-1]
    print(res)