import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = [*map(int, input().split())]
    del s[0]
    e, o = 0, 0
    for c in s:
        if c&1: o += c
        else: e += c
    if o==e:
        print("TIE"); continue
    print(["ODD","EVEN"][o<e])