from decimal import Decimal as D
from sys import stdin
p=D(stdin.readline())
while True:
    n=D(stdin.readline())
    if n==999: break
    print("%.2f"%float(n-p))
    p=n
