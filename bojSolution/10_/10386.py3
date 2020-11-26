import sys
import fractions
input = sys.stdin.readline
F = fractions.Fraction

def rev(f):
    return F(f.denominator, f.numerator)

def magic(s, i):
    if i==len(s)-1:
        return F(s[i], 1)
    return F(s[i], 1) + rev(magic(s, i+1))

def con(f):
    print(f.numerator//f.denominator, end=" ")
    f -= f.numerator//f.denominator
    if f.numerator != 0:
        con(rev(f))

TEST = 0
while 1:
    TEST += 1
    n, m = map(int, input().split())
    if n==0 and m==0: break
    A = magic([*map(int, input().split())], 0)
    B = magic([*map(int, input().split())], 0)
    print("Case %d:"%TEST)
    con(A+B); print()
    con(A-B); print()
    con(A*B); print()
    con(A/B); print()