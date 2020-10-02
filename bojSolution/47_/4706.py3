from decimal import Decimal as D
from sys import stdin
c=D(299792458)**2
while True:
    a,b=map(D,stdin.readline().split())
    if a==b and a==0: break
    print("%.3f"%float((c-c*((b/a)**2)).sqrt()/c.sqrt()))
