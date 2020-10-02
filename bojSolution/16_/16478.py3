from decimal import Decimal as D
from sys import stdin
def input(): return stdin.readline().rstrip()
a,b,c=map(D,input().split())
print(a*c/b)