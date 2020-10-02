from sys import stdin
from decimal import Decimal as D

T=int(stdin.readline())
for _ in range(T):
    li=sorted(list(map(D,stdin.readline().split())))
    print("Scenario #",_+1,":",sep="")
    print(["no","yes"][li[0]**2+li[1]**2==li[2]**2])
    print()