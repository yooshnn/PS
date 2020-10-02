from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s = input().split()
    r = float(s[0])
    for c in s:
        if c=='@': r *= 3
        if c=='%': r += 5
        if c=='#': r -= 7
    print("%.2f" % r)