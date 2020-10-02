from sys import stdin
def input(): return stdin.readline().rstrip()

a, b = 0, 0
aw, bw = 0, 0
res = []
G = input()
for g in G:
    if g == "A": a += 1
    else: b += 1
    if a == 21 or b == 21:
        res.append(str(a)+"-"+str(b))
        if a > b: aw += 1
        else: bw += 1
        if aw == 2 or bw == 2: break
        a, b = 0, 0
print(*res, sep="\n")
print("A" if aw>bw else "B")