import sys; input = sys.stdin.readline

s = set()
t = 0

for c in input().rstrip():
    if '0'<=c<='9':
        t = (t * 10) + (ord(c) - ord('0'))
    else:
        if t!=0:
            s.add(t)
            t = 0

if t!=0: s.add(t)

print(len(s))