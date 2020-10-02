from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

t, a, b = map(D, input().split())
isNone = True

for i in range(0, int(t/a+1)):
    if (t - a * i) % b == 0:
        isNone = False
        print(i, int((t - a * i) / b))

if isNone: print("none")