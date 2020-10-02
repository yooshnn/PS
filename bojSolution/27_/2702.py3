from sys import stdin
from math import gcd
T=int(stdin.readline())
for _ in range(T):
    x,y=map(int,stdin.readline().split())
    print(x*y//gcd(x,y),gcd(x,y))