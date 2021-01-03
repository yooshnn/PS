import sys; input=sys.stdin.readline
import math
import collections; deque = collections.deque

n = int(input())
s = [*map(int, input().split())]
g = s[0]
for i in range(1, n): g = math.gcd(g, s[i])

r1 = deque()
r2 = deque()

i = 1
while i*i<=g:
    if g%i==0:
        r1.append(i)
        if g//i != i: r2.appendleft(g//i)
    i += 1

print(*r1, sep="\n")
print(*r2, sep="\n")
