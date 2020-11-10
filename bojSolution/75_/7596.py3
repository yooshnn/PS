import sys
input = sys.stdin.readline

t = 1
c = 1
while t:
    t = int(input())
    if t!=0:
        print(c)
    li = []
    for _ in range(t):
        li.append(input().rstrip())
    print(*sorted(li), sep="\n")
    c += 1