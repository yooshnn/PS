from sys import stdin
T=int(stdin.readline())
A=[]
B=[]
for _ in range(T):
    n,m=map(int,stdin.readline().split())
    A=list(map(int,stdin.readline().split()))
    B=list(map(int,stdin.readline().split()))
    res=list(set(A) & set(B))
    if len(res)==0:
        print("NO")
    else:
        print("YES")
        print(1,res[0])
