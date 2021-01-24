import sys; input = sys.stdin.readline

L = int(input())
s = [*map(int, input().split())]
dup = set()

def check(b, c):
    if c in dup: return False
    if b==1:
        if c==3 and (2 not in dup): return False
        if c==7 and (4 not in dup): return False
        if c==9 and (5 not in dup): return False
    if b==2:
        if c==8 and (5 not in dup): return False
    if b==3:
        if c==1 and (2 not in dup): return False
        if c==7 and (5 not in dup): return False
        if c==9 and (6 not in dup): return False
    if b==4:
        if c==6 and (5 not in dup): return False
    if b==6:
        if c==4 and (5 not in dup): return False
    if b==7:
        if c==1 and (4 not in dup): return False
        if c==3 and (5 not in dup): return False
        if c==9 and (8 not in dup): return False
    if b==8:
        if c==2 and (5 not in dup): return False
    if b==9:
        if c==1 and (5 not in dup): return False
        if c==3 and (6 not in dup): return False
        if c==7 and (8 not in dup): return False
    return True

if L<3:
    print("NO"); sys.exit(0)

good = True
b = s[0]
dup.add(b)

for i in range(1, L):
    c = s[i]
    if not check(b, c): good = False
    dup.add(c); b = c

if good: print("YES")
else: print("NO")