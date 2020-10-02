from decimal import Decimal as D
from sys import stdin
def input(): return stdin.readline()
a,b=map(D,input().split())
print(a/b)