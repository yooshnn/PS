import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
c = [*map(int, input().split())]

for i in range(m):
    q = int(input())+1
    if q <= n:
        print(c[q-1])
    else:
        print(c[(k-1)+(q-k)%(n-k+1)])
