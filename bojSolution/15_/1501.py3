import sys
input = sys.stdin.readline

d = {}

for i in range(int(input())):
    s = input().rstrip()
    try:
        d[s[0]+s[-1]+str(sorted(s))] += 1
    except:
        d[s[0]+s[-1]+str(sorted(s))] = 1

for j in range(int(input())):
    s = input().split()
    res = 1
    for c in s:
        try:
            res *= d[c[0]+c[-1]+str(sorted(c))]
        except:
            res *= 0
    print(res)