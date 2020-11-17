import sys
import math
input = sys.stdin.readline
gcd = math.gcd

d = {}
for _ in range(int(input())):
    n, m = map(int, input().split())
    n, m = n//gcd(n, m), m//gcd(n, m)
    try:
        d[(n, m)] += 1
    except:
        d[(n, m)] = 1
print(max(d.values()))