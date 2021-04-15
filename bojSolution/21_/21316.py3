import sys; input = sys.stdin.readline

indeg = [0 for i in range(13)]
mark = [[0 for i in range(13)] for j in range(3)]
adj = [[] for i in range(13)]

for i in range(12):
    u, v = map(int, input().split())
    assert(1<=u<=12 and 1<=v<=12 and u!=v)
    indeg[u] += 1
    indeg[v] += 1
    adj[u].append(v)
    adj[v].append(u)

for i in range(1, 13):
    if indeg[i]==3: mark[0][i] = 1
    if indeg[i]==1: mark[1][adj[i][0]] = 1
    if indeg[i]==2: mark[2][adj[i][0]] = mark[2][adj[i][1]] = True

for i in range(1, 13):
    if mark[0][i] and mark[1][i] and mark[2][i]: print(i)