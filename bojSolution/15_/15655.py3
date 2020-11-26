import sys
from itertools import combinations
input = sys.stdin.readline

n, m = map(int, input().split())
s = [*map(int, input().split())]; s.sort()

for c in combinations(s, m):
    print(*c)