import sys
import math
input = sys.stdin.readline
gcd = math.gcd

li = []

T = int(input())
for _ in range(T):
    li.append(int(input()))
g = li[1]-li[0]
for i in range(1, T):
    g = gcd(g, li[i]-li[i-1])

s = set(li)
res = 0

print((li[-1]-li[0])//g-len(li)+1)
