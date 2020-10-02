from sys import stdin
from decimal import Decimal as D

N,c=map(int,stdin.readline().split())
l=list(map(D,stdin.readline().split()))

if c==0:
    good=l[0]
    bad=l[1]
else:
    good=l[2]
    bad=l[3]

for _ in range(N-1):
    goodold=good
    badold=bad
    good=(goodold*l[0]+badold*l[2])
    bad=(badold*l[3]+goodold*l[1])

good=int(good*1000)

print(good,1000-good,sep="\n")
