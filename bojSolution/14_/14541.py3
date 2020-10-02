while 1:
    T=int(input())
    if T==-1:break
    py=0
    s=0
    while T>0:
        T-=1
        x,y=map(int,input().split())
        s+=(x*(y-py))
        py=y
    print(s,"miles")