from sys import stdin
from math import gcd
def lcm(a, b): return (a * b) // gcd(a, b)
def input(): return stdin.readline().rstrip()

s, t = input(), input()
s *= lcm(len(s), len(t)) // len(s)
t *= lcm(len(s), len(t)) // len(t)

print(1 if s==t else 0)