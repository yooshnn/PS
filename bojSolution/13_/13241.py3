from sys import stdin
from math import gcd
input = stdin.readline

a, b = map(int, input().split())
print(a*b//gcd(a, b))