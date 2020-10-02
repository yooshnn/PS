from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

a,b=map(int,input().split())
M=(b-a)/400
print(1/(1+10**M))