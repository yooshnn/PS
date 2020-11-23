import sys
import math
input = sys.stdin.readline
gcd = math.gcd

a = [*map(int, input().split())]
b = [*map(int, input().split())]
c, d = 0, 36

for i in a:
    for j in b:
        if i>j: c+= 1

print(c//gcd(c,d),d//gcd(c,d),sep="/")