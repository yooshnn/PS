from sys import stdin
from math import gcd
def input(): return stdin.readline().rstrip()
a, b = map(int, input().split())
print(gcd(a, b))