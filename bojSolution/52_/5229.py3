import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    p = set()
    s = [*map(int, input().split())]
    for i in range(1, s[0]*2+1, 2):
        p.add((s[i], s[i+1]))
    res = {}
    for cur in p:
        cr, cc = cur
        x = 1
        while 1:
            if (cr + x, cc) in p and (cr + x, cc + x) in p and (cr, cc + x) in p:
                try: res[x] += 1
                except: res[x] = 1
            x += 1
            if cr+x>30 or cc+x>30: break
    M, L = 0, 0
    for key in sorted(res.keys()):
        if res[key]>=M:
            M, L = res[key], key
    if L==0 and M==0:
        print("No squares among the points.")
    else:
        print("LENGTH = %d, COUNT = %d"%(L, M))