import sys
import decimal
import itertools
input = sys.stdin.readline
D = decimal.Decimal

s = itertools.permutations([*map(D, input().split())])
minV = 2147483647
res = ()

for p in s:
    cur = p[0]/p[1] + p[2]/p[3]
    if cur<minV:
        minV = cur
        res = p

print(*res)