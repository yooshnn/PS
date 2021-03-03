import sys; input = sys.stdin.readline

n = int(input())
s = [[c, i+1] for i, c in enumerate([*map(int, input().split())])]
cnt = sum([i[0] for i in s])
bad = False
res = []

while 1:
    s.sort(reverse=True)
    if s[0][0]>0 and s[1][0]>0:
        s[0][0] -= 1
        s[1][0] -= 1
        cnt -= 2
        res.append((s[0][1], s[1][1]))
    else:
        bad = True
    if bad or cnt==0: break

if bad and cnt>0: print("no")
else:
    print("yes")
    for i in res:
        print(*i)