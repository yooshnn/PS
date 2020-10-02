from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    t = int(input())
    if t == 0: break
    o = []
    u = []
    for _ in range(t):
        s = input()
        o.append(s)
        u.append(s.upper())
    f = min(u)
    for oi in o:
        if f == oi.upper():
            print(oi)
            break