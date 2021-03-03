import sys; input = sys.stdin.readline

m = ["A", "B", "C", "AA", "AB", "AC", "BA", "BB", "BC", "CA", "CB", "CC", "AAA", "AAB", "AAC", "ABA", "ABB", "ABC", "ACA", "ACB", "ACC", "BAA", "BAB", "BAC", "BBA", "BBB", "BBC", "BCA", "BCB", "BCC", "CAA", "CAB", "CAC", "CBA", "CBB", "CBC", "CCA", "CCB", "CCC"]
S, T = input().rstrip(), input().rstrip()

res = []

def multate(s, h0, h1, h2):
    ret = False

    if h0=="-": p = 0
    elif h1=="-": p = 1
    elif h2=="-": p = 2
    else: return

    for c in "ABC":
        for i in m:
            t = s.replace(c, i)
            if p==0: h0 = c+" "+i
            elif p==1: h1 = c+" "+i
            else: h2 = c+" "+i

            if t==T:
                temp = []
                if h0!="-": temp.append(h0)
                if h1!="-": temp.append(h1)
                if h2!="-": temp.append(h2)
                res.append([len(temp), temp])
                return
            else:
                multate(t, h0, h1, h2)

multate(S, "-", "-", "-")

print(*sorted(res)[0][1], sep="\n")