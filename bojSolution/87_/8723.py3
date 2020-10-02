from sys import stdin
from decimal import Decimal as D
li=sorted(map(D,stdin.readline().split()))
if li[2]**2 == li[1]**2+li[0]**2:
    print(1)
elif li[0]==li[1] and li[1]==li[2]:
    print(2)
else:
    print(0)