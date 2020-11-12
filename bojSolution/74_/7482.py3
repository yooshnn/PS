import sys
import decimal
input = sys.stdin.readline
D = decimal.Decimal

for _ in range(int(input())):
    a = D(input())

    left, right = 0, a/2
    x = (left + right)/2
    while left < right:
        x = (left + right)/2
        calc = 12*(x**2) - 8*a*x + a**2
        if calc < 0:
            right = x
        else:
            left = x
        if D(-1/100000000000) <= calc <= D(1/100000000000):
            break
    print(x.quantize(D(".0000000001")))
