N,K=map(int,input().split())
H=0
M=0
S=0
res=0
while True:
    H_ = str(H) if H >= 10 else "0"+str(H)
    M_ = str(M) if M >= 10 else "0"+str(M)
    S_ = str(S) if S >= 10 else "0"+str(S)
    if str(K) in H_+M_+S_:
        res+=1
    S+=1
    if S==60:
        S=0
        M+=1
        if M==60:
            M=0
            H+=1
            if H>N:
                break
print(res)
