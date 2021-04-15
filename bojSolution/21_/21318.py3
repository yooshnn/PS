import sys; input = sys.stdin.readline

N = int(input())
assert(1<=N<=100000)

g = [-1]
l = int(2e9)
for i, c in enumerate([*map(int, input().split())]):
    assert(1<=c<=1000000000)
    g.append(g[i] + (1 if l>c else 0))
    l = c

Q = int(input())
assert(1<=Q<=100000)

for i in range(Q):
    x, y = map(int, input().split())
    assert(1<=x and x<=y and y<=N)

    print(str(g[y]-g[x]))