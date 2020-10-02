from sys import stdin
from decimal import Decimal as D
input = stdin.readline

x1, y1, z1, x2, y2, z2 = map(D, input().split())
d = ((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2).sqrt()
N = int(input())
s = list(map(D, input().split()))

M = max(d, max(s))
R = d + sum(s) - M

if M <= R:
    print("YES")
else:
    print("NO")