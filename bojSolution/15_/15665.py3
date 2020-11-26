import sys
from itertools import product
input = sys.stdin.readline

dup = set()

n, m = map(int, input().split())
s = [*map(int, input().split())]; s.sort()

for c in product(s, repeat=m):
    if c in dup: continue
    dup.add(c)
    print(*c)