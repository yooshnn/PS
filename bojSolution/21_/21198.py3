import sys; input = sys.stdin.readline
import fractions

def getc(t: tuple):
    global pa
    return t[0] + pa*(t[1] - t[0])

def solve(n: int, t: tuple, s: str):
    global encodedFraction

    guessA = (t[0], getc(t))
    guessB = (getc(t), t[1])

    if n==1:
        if guessA[0]==encodedFraction: print(s+"A")
        elif guessB[0]==encodedFraction: print(s+"B")
    else:
        solve(n-1, guessA, s+"A")
        solve(n-1, guessB, s+"B")

N = int(input())
pa = fractions.Fraction(int(input()), 8)
encoded = input().rstrip()[2:]
encodedFraction = 0

for i, c in enumerate(encoded):
    if c=='1': encodedFraction += fractions.Fraction(1, 2**(i+1))

solve(N, (0, 1), "")
