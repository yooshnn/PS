import sys; input = sys.stdin.readline
import itertools

for TEST in range(int(input())):
    li = [*map(int, input().split())]
    li = sorted(li[1:])
    res = []
    for i in itertools.combinations(li, 3):
        if i[0]*i[0]+i[1]*i[1]==i[2]*i[2]:
            res.append(i)
    dup = set()
    if len(res)==0:
        print("No Pythogorean triples found in the sequence.", end="")
    else:
        print("Found Pythogorean triples:  ", end="")
        proc = []
        for r in res:
            if r not in dup:
                dup.add(r)
                app = []
                for x in r:
                    tmp = []
                    for c in str(x):
                        tmp.append(str(c))
                    app.append(tmp)
                proc.append(app)
        proc.sort()
        rr = []
        for cc in proc:
            t = []
            for ccc in cc:
                t.append("".join(ccc))
            rr.append(" ".join(t))
        for r in rr:
            print("{%s}"%"".join(r), end=" ")
    print()
