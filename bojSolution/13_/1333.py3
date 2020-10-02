from sys import stdin
N,L,D=map(int,stdin.readline().split())
NN=N
res=0
flag=False
while N>0:
    N-=1
    res+=L
    for i in range(1,6):
        if res%D==0:
            print(res)
            N=0
            flag=True
            break
        res+=1
if not flag:
    res=NN*(L+5)-5
    while res%D!=0:
        res+=1
    print(res)
