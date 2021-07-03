import sys; input = sys.stdin.readline

d = {}
M = 0
res = ""

for i in range(int(input())):
    s = input().rstrip()
    try: d[s] += 1
    except: d[s] = 1
    M = max(M, d[s])

for i in sorted(d.keys()):
    if d[i]==M:
        print(i)
        break