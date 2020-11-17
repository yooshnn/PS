import sys
import decimal
input = sys.stdin.readline
D = decimal.Decimal
decimal.getcontext().prec = 2800


n, m, h, w = map(D, input().split())
p, q = m, n

r1, r2 = 0, 0
while n>h or m>w:
    if n>h:
        n /= 2
        r1 += 1
    if m>w:
        m /= 2
        r1 += 1
while p>h or q>w:
    if p>h:
        p /= 2
        r2 += 1
    if q>w:
        q /= 2
        r2 += 1

print(min(r1, r2))