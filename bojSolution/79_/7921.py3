from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    N=3*D(input())/7
    if (_+1)%69==0:
        print("AMPPZ 2010")
        continue
    print(round(N,0))