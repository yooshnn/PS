from sys import stdin
from math import gcd
def input(): return stdin.readline().rstrip()
def lcm(a, b): return a*b / gcd(a, b)

for _ in range(int(input())):
    a, b = map(int, input().split())
    print(int(lcm(a, b)))