from sys import stdin
from decimal import Decimal as D
from math import gcd

a, b = map(int, input().split())
print("1"*gcd(a,b ))
