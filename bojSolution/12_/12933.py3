from sys import stdin
def input(): return stdin.readline().rstrip()

def quack(q):
    for i, c in enumerate("quack"):
        if c == q: return i+1

res, bad = 0, False
duck = []
s = input()

for c in s:
    if bad: break
    if c == "q":
        duck.append(1)
    elif c == "k":
        f = False
        for i, d in enumerate(duck):
            if d == quack(c)-1:
                f = True
                duck.pop(i)
                break
        if not f: bad = True
    else:
        f = False
        for i, d in enumerate(duck):
            if d == quack(c)-1:
                f = True
                duck[i] = quack(c)
                break
        if not f: bad = True
    res = max(res, len(duck))

print(res if len(duck)==0 and not bad else -1)