from sys import stdin
from math import floor
import decimal
D = decimal.Decimal
input = stdin.readline

decimal.getcontext().prec = 28000
g = D(1/(10**200))

p, m = D(input()), D(input())
pmax, mmax = 1/p, 1/m
pmin, mmin = 1/(p+1) + g, 1/(m+1) + g

print(floor(mmin/pmax))
print(floor(mmax/pmin))
