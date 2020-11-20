import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().rstrip()
    g, b = s.upper().count("G"), s.upper().count("B")
    if g>b: print("%s is GOOD"%s)
    elif g<b: print("%s is A BADDY"%s)
    else: print("%s is NEUTRAL"%s)