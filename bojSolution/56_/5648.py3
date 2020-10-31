import sys
input = sys.stdin.readline

li = []
f = True

while 1:
    line = input()
    if not line: break
    s = line.split()
    if f:
        f = False
        if len(s)==1: continue
        s=s[1:]
    for c in s:
        li.append(int(c[::-1]))

li = sorted(li)
print(*li, sep="\n")
