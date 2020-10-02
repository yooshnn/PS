from sys import stdin
from math import gcd
A, B, C, D, E, F = map(int, stdin.readline().split())
p = [A, B, C]
q = [D, E, F]

def calc(a, b):
    if a[0] == 0:
        y = a[2]//a[1]
        x = (b[2] - b[1]*y) // b[0]
    elif a[1] == 0:
        x = a[2]//a[0]
        y = (b[2] - b[0]*x) // b[1]
    elif b[0] == 0:
        y = b[2]//b[1]
        x = (a[2] - a[1]*y) // a[0]
    elif b[1] == 0:
        x = b[2]//b[0]
        y = (a[2] - a[0]*x) // a[1]
    else:
        ad_lcm = gcd(a[0], b[0]) * a[0] * b[0]
        a_multiplier = ad_lcm // a[0]
        d_multiplier = ad_lcm // b[0]
        y = (a[2]*a_multiplier-b[2]*d_multiplier)//(a[1]*a_multiplier-b[1]*d_multiplier)
        x = (a[2] - (a[1] * y)) // a[0]
    return list([x,y])

res = calc(p, q)
print(res[0],res[1])