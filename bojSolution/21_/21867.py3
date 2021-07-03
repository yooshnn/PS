import sys; input = sys.stdin.readline

n = int(input())
s = input().rstrip()
f = True

for c in s:
    if c in "JAV": continue
    f = False
    print(c, end="")

if f: print("nojava")