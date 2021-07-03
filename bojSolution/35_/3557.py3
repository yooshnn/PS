import sys; input = sys.stdin.readline

d = {}
c = set()

for TEST in range(int(input())):
    o, n = input().split(); n = int(n)
    if o[0]=="i":
        try: d[n] += 1
        except: d[n] = 1
        if d[n]>1: c.add(n)
    else:
        try:
            if d[n]==1: del d[n]
            else:
                d[n] -= 1
                if d[n]<2: c.remove(n)
        except: pass

    hetero = True if len(d)>1 else False
    homo = True if len(c)>0 else False

    if homo and hetero:
        print("both")
    elif homo:
        print("homo")
    elif hetero:
        print("hetero")
    else:
        print("neither")
