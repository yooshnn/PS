import sys
import math
input = sys.stdin.readline

def solve(n):
    s = 104730
    prime = [True] * s

    for i in range(2, math.floor(math.sqrt(s))):
        if prime[i]:
            for j in range(i*2, s, i):
                prime[j] = False

    i = 2
    while 1:
        if prime[i]:
            n -= 1
            if n==0: return i
        i += 1

print(solve(int(input())))
