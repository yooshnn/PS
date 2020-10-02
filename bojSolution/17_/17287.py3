from sys import stdin
def input(): return stdin.readline().rstrip()

s, p, r = input(), 0, 0
for c in s:
    if c=="(": p += 1
    if c=="{": p += 2
    if c=="[": p += 3
    if c==")": p -= 1
    if c=="}": p -= 2
    if c=="]": p -= 3
    if c>='0' and c<='9': r = max(r, p)
        
print(r)