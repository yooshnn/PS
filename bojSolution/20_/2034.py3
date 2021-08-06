import sys; input = sys.stdin.readline

base = [0, -1, 1, -1, 2, 3, -1, 4, -1, 5, -1, 6]
init = [0, 2, 4, 5, 7, 9, 11]
res = "ABCDEFG"

adj = [base[init[i]:] + base[:init[i]] for i in range(7)]

n = int(input())
s = [int(input()) for i in range(n)]

for i in range(7):
    f = (i+5)%7
    for c in s:
        t = (-(abs(c)%12) if c<0 else abs(c)%12)
        f = adj[f][t]
        if f==-1: break
    if f!=-1:
        print(res[i], res[(f+2)%7])
