import sys
import fractions
input = sys.stdin.readline
F = fractions.Fraction

n = int(input())
s = [*map(int, input().split())]

def rev(f):
    return F(f.denominator, f.numerator)

def magic(i):
    if i==n-1:
        return F(s[i], 1)
    return F(s[i], 1) + rev(magic(i+1))

print(magic(0))