import sys; input=sys.stdin.readline

r, c = map(int, input().split())
mat = [[int(x) for x in input().split()] for i in range(r)]

for i in range(r):
    t = [*map(int, input().split())]
    for k in range(c):
        mat[i][k] += t[k]

for i in mat:
    print(*i)
