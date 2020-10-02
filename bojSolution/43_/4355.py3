from sys import stdin
m={}

while True:
    N=int(stdin.readline())
    m.clear()
    k=2
    res=1

    if N==0:
        break
    if N==1:
        print(1)
    else:
        while k*k<=N:
            if N%k==0:
                try:
                    m[k]+=1
                except:
                    m[k]=1
                N//=k
            else:
                k+=1
        try:
            m[N]+=1
        except:
            m[N]=1

        for key in m:
            res *= key**m[key] - key**(m[key]-1)
        print(res)
