from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    line = input()
    if not line: break
    s, t = line.split()
    if len(s) > len(t):
        print("No"); continue
    p, q = 0, -1
    while 1:
        q = t.find(s[p], q + 1)
        if q == -1: break
        else: p += 1
        if p==len(s): break
    if p==len(s): print("Yes")
    else: print("No")