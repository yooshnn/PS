from sys import stdin

def bfs():
    Q=[p]
    visit[p]=1
    while len(Q)>0:
        cur=Q.pop(0)
        for i in range(1,n+1):
            if d[cur][i]==1 and visit[i]==0:
                visit[i]=visit[cur]+1
                Q.append(i)

n=int(stdin.readline())
p,q=map(int,stdin.readline().split())
m=int(stdin.readline())
d=[[0]*(n+1) for i in range(n+1)]
visit=[0]*(n+1)

for i in range(m):
    a,b=map(int,stdin.readline().split())
    d[a][b]=1
    d[b][a]=1

bfs()
print(visit[q]-1)