from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

h,v=map(D,input().split())
d=(h*h+v*v).sqrt()
a=v*h/(d+h)
b=v-a
p=(a*a+h*h).sqrt()/2
q=(b*h)/p/2
print("%.2f"%float(p),"%.2f"%float(q))