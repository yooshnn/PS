from sys import stdin
from math import gcd
input = stdin.readline
def lcm(p, q): return p*q//gcd(p, q)

N = int(input())
num, den = 1, -1
fracs = []

for i in range(N):
    a, b = map(int, input().split())
    fracs.append((a, b))
    num = lcm(num, b)

for f in fracs:
    den = f[0]*num//f[1] if den == -1 else gcd(den, f[0]*num//f[1])
    if den == 1: break

print(den//gcd(num, den), num//gcd(num, den))