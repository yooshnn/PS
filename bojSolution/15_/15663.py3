import sys
from itertools import permutations
input = sys.stdin.readline

dup = set()

n, m = map(int, input().split())
s = [*map(int, input().split())]; s.sort()

for c in permutations(s, m):
    if not c in dup:
        print(*c)
        dup.add(c)