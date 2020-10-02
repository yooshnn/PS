from sys import stdin
N,M=map(int,stdin.readline().split())
S=str(stdin.readline().strip())
for _ in range(M):
    s=S
    q=str(stdin.readline().strip())
    while len(s)>0:
        p=q.find(s[0])
        if p==-1:
            break
        s=s[1:]
        q=q[p+1:]
    print(["false","true"][len(s)==0])
