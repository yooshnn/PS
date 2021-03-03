import sys; input = sys.stdin.readline
from math import gcd

N = int(input())
x = []

t0 = int(input())
for _ in range(N-1):
    t = int(input())
    x.append(t-t0)
    t0 = t

try: g = gcd(*x)
except: g = x[0]
res = set()

for i in range(2, g+1):
    if g%i==0: res.add(i), res.add(g//i)
    if i*i>g: break

res.add(g)
print(*sorted(res))
