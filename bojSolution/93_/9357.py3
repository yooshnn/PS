import sys
input = sys.stdin.readline

for _ in range(int(input())):
    dup = set()
    participants = dict()
    for n in range(int(input())):
        s = input().rstrip()
        name = s
        for i in range(10):
            name = name.replace(str(i), "")
        name = name.rstrip()
        year = s.split()[-1]
        if (name, year) in dup: continue
        dup.add((name, year))
        try: participants[name] += 1
        except: participants[name] = 1
    print("Case #%d:"%(_+1))
    res = []
    for keys in participants:
        if participants[keys] < 5:
            res.append(keys)
    print(*sorted(res), sep="\n")
