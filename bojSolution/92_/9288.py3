for _ in range(int(input())):
    n=int(input())
    print("Case %s:"%str(_+1))
    for i in range(1,n//2+1):
        for j in range(6,0,-1):
            if i+j==n:print("(%d,%d)"%(i,j))