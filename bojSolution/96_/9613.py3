from math import gcd
from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    s=list(map(int,stdin.readline().split()))[1:]
    z=0
    for i in range(len(s)-1):
        for j in range(i+1,len(s)):
            z+=gcd(s[i],s[j])
    print(z)
