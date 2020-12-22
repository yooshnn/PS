import sys; input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
r = [-1 for x in range(n)]

for i, c in enumerate(s):
    cnt = 0
    for j in range(n):
        if r[j]==-1:
            if cnt==c:
                r[j] = i+1
                break
            else:
                cnt += 1
print(*r)