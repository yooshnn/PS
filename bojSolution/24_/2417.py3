import sys; input = sys.stdin.readline
import math

N = int(input())
t = max(0, int(math.sqrt(N)) - 10)

while 1:
    if t*t>=N:
        print(t)
        break
    else: t += 1