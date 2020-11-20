import sys
import math
input = sys.stdin.readline
gcd = math.gcd

def lcm(a, b):
    return a*b//gcd(a, b)

for TEST in range(int(input())):
    a, b, c, d = map(int, input().split())
    denom = lcm(b, d)
    aMul, cMul = denom//b, denom//d
    a, b, c, d = a*aMul, denom, c*cMul, denom
    num = lcm(a, c)
    num, denom = num//gcd(num, denom), denom//gcd(num, denom)
    print(num, denom)