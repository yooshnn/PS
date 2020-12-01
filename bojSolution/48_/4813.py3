import sys
input = sys.stdin.readline

Case = 0
while 1:
    Case += 1
    N, MAXLEN = map(int, input().split())
    if MAXLEN==0: break
    res = set()
    pri = []
    dup = {}
    for _ in range(N):
        raw = input().lower().split()
        cur = []
        fn, ln = raw[0], raw[-1]
        for c in fn:
            if c!="-" and c!="'":
                cur.append(c); break
        for c in ln:
            if c!="-" and c!="'":
                cur.append(c)
                if len(cur)==MAXLEN: break
        cur = "".join(cur)
        if cur not in res:
            res.add(cur)
            pri.append(cur)
            continue

        if len(cur)+1 <= MAXLEN: temp = cur
        else: temp = cur[:-1]

        cont = True
        try: b = dup[cur]
        except: b = 1

        if b<10:
            for i in range(b, 10):
                if temp+str(i) not in res:
                    dup[cur] = i+1
                    res.add(temp+str(i))
                    pri.append(temp+str(i))
                    cont = False
                    break
        if cont:
            temp = cur[:min(len(temp), MAXLEN-2)]
            for i in range(b, 100):
                if temp+str(i) not in res:
                    dup[cur] = i+1
                    res.add(temp+str(i))
                    pri.append(temp+str(i))
                    break

    print("Case", Case)
    print(*pri, sep="\n")

    