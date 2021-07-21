import sys; input = sys.stdin.readline
from math import gcd

n, m, k = map(int, input().split())
n += 1
m += 1
nm = n * m // gcd(n, m)

b = k//nm
c = k//m - b
d = k//n - b
a = k - b - c - d

print(a, b, c, d)