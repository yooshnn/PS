import sys
from itertools import product
input = sys.stdin.readline

n, m = map(int, input().split())
s = [*map(int, input().split())]; s.sort()

for c in product(s, repeat=m):
    print(*c)