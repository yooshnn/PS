import sys
input = sys.stdin.readline

for i in range(int(input())):
    s = input().rstrip().upper()
    r = ""
    res = True
    for c in s:
        if c<='C': r += "2"
        elif c<='F': r += "3"
        elif c<='I': r += "4"
        elif c<='L': r += "5"
        elif c<='O': r += "6"
        elif c<='S': r += "7"
        elif c<='V': r += "8"
        else: r += "9"
    for i in range(len(r)//2):
        if r[i] != r[len(r)-1-i]: res = False
    print("YES" if res else "NO")