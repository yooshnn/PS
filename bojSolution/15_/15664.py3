import sys
from itertools import permutations
input = sys.stdin.readline

dup = set()

n, m = map(int, input().split())
s = [*map(int, input().split())]; s.sort()

for c in permutations(s, m):
    if c in dup: continue
    dup.add(c)

    good = True
    for i in range(1, m):
        if c[i]<c[i-1]: good = False
    if good: print(*c)