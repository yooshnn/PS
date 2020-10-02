for _ in range(int(input())):
    N,D=map(int,input().split())
    r=0
    for i in range(N):
        a,b,c=map(int,input().split())
        if a*(b/c)>=D:
            r+=1
    print(r)