import sys; input = sys.stdin.readline
import itertools

res = 0
rep = set()

for _ in range(int(input())):
    rep.add(tuple(map(int, input().split())))

for i in range(111, 1000):
    cur = str(i)
    if len(set(i for i in cur))!=3: continue
    if "0" in cur: continue
    good = True
    for r in rep:
        tar, s, b = r; tar = str(tar)
        sc, bc = 0, 0
        for k in range(3):
            if tar[k]==cur[k]: s -= 1
            elif tar[k] in cur: b -= 1
        if s!=0 or b!=0: good = False
        if not good: break
    if good: res += 1

print(res)