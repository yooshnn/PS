import sys
input = sys.stdin.readline

while 1:
    N, ISSUER = input().split(); N = int(N)
    if N==0 and ISSUER=="END": break

    buy, sell = [], []
    exc = []

    for _ in range(N):
        h, t, v = input().split(); v = float(v)
        if t=="buy":
            buy.append([v, h])
        if t=="sell":
            sell.append([v, h])
        exc.append([h, t, v])

    print(ISSUER)
    for e in exc:
        res = []
        if e[1]=="buy":
            for i in sell:
                if i[0]<=e[2]:
                    res.append(i[1])
        if e[1]=="sell":
            for i in buy:
                if i[0]>=e[2]:
                    res.append(i[1])

        if len(res)==0:
            print("%s: NO-ONE"%e[0])
        else:
            print("%s: %s"%(e[0], " ".join(res)))