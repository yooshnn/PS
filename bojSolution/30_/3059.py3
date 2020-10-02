from sys import stdin
t = int(stdin.readline())


for i in range(t):
    s = stdin.readline()[:-1]
    ss = set(s)
    res = 0
    for asc in range(65,91):
        if chr(asc) not in ss:
            res += asc
    print(res)