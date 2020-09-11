from sys import stdin
from math import gcd
def lcm(a, b):
    return a * b / gcd(a, b)
T=int(stdin.readline())
for _ in range(T):
    l,r=map(int,stdin.readline().split())
    if l==1:
        print(1,2)
    else:
        if lcm(l,int(l*(1.5)))<=r:
            print(l,int(l*(1.5)))
        elif lcm(l,int(l*2))<=r:
            print(l,int(l*2))
        else:
            l+=1
            if lcm(l,int(l*(1.5)))<=r:
                print(l,int(l*(1.5)))
            elif lcm(l,int(l*2))<=r:
                print(l,int(l*2))
            else:
                print(-1,-1)
