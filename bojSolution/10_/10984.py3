from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    n=int(stdin.readline())
    c=0
    g=0
    for i in range(n):
        x,y=map(float,stdin.readline().split())
        c+=x
        g+=x*y
    print(int(c),"%.1f"%(g/c))
