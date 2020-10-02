from math import gcd
def lcm(a,b):
    return a*b//gcd(a,b)
    
a,b = input().split()
a = int(a)
b = int(b)
print(gcd(a,b))
print(lcm(a,b))