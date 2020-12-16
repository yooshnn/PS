import sys
input = sys.stdin.readline

n, m, s = map(int, input().split())
p = [[*map(int, input().split())] for i in range(n)]
p.extend([[0, 0]])
p.sort()

for i in range(1, n+1):
    if (p[i][0])-(p[i-1][0]+p[i-1][1])>=m:
        print(p[i-1][0]+p[i-1][1])
        sys.exit(0)

if s-(p[-1][0]+p[-1][1])>=m:
    print(p[-1][0]+p[-1][1])
    sys.exit(0)

print(-1)
