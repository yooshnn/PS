from sys import stdin
from math import sqrt
from decimal import Decimal as D
a,b,c = map(D,stdin.readline().split())

sad = (a+b+c)/D(2)
_S = (sad*(sad-a)*(sad-b)*(sad-c)).sqrt()
_R = a*b*c/D(4*_S)
_r = 2*_S/(a+b+c)
_d = D(max(0,_R*(_R-2*_r))).sqrt()
_k = D(D(_R**2 - (a/2)**2).sqrt() + D(_R**2 - (b/2)**2).sqrt() + D(_R**2 - (c/2)**2).sqrt())

print(_S)
print(_R)
print(_r)
print(_d)
print(_k)