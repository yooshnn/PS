from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    n,m=map(int,stdin.readline().split())
    c=0
    for i in range(1,n-1):
        for j in range(i+1,n):
            if (i**2+j**2+m)/(i*j)%1==0:
                c+=1
    print(c)
