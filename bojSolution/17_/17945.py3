from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

a,b=map(D,input().split())

x=(-a+(a*a-b).sqrt())
y=(-a-(a*a-b).sqrt())
s=sorted(set([x,y]))
print(*s)