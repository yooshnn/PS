from decimal import Decimal as D
from sys import stdin
def input(): return stdin.readline().rstrip()
while 1:
    n=D(input())
    if n==0:break
    if n<=1000000:
        print(n)
    elif n<=5000000:
        print(n*9/10)
    else:
        print(n*8/10)