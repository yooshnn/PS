import sys; input=sys.stdin.readline
import math; gcd=math.gcd

a,b=map(int, input().split(":"))
print(a//gcd(a,b),":",b//gcd(a,b),sep="")
