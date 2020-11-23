import sys
input = sys.stdin.readline
def cv(a): return bool('a'<=a<='z')+(ord(a)-ord("Aa"['a'<=a<='z']))*2
w = []
for _ in range(int(input())):
    s, d = input().rstrip(), []
    l = not s[0].isdigit()
    for c in s:
        if c.isdigit()==l:
            if c.isdigit(): d[-1]=[0,d[-1][1]*10+int(c),d[-1][2]+1]
            else: d[-1][1].append(cv(c))
        else:
            if c.isdigit(): d.append([0, int(c), 1])
            else: d.append([1, [cv(c)]])
        l = c.isdigit()
    w.append([d, s])
for r in sorted(w): print(r[1])