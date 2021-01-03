import sys; input=sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    t = input().split()
    s = []
    dic = {}
    for type in t:
        try:
            if dic[type]<3:
                dic[type] += 1
                s.append(type)
        except:
            dic[type] = 1
            s.append(type)
    n = len(s)
    res = 2000000
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                tt = 0
                for l in range(4):
                    if s[i][l]!=s[j][l]: tt += 1
                    if s[i][l]!=s[k][l]: tt += 1
                    if s[j][l]!=s[k][l]: tt += 1
                res = min(res, tt)
    print(res if res!=2000000 else 0)
