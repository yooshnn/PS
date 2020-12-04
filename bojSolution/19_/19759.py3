import sys
import math
input = sys.stdin.readline

t = 100
for i in range(int(input())):
    print(t)
    t *= 2
    t = str(t)
    if t[len(t)//2]!="0":
        t = str(int(t[:len(t)//2])+1)+("0"*((len(t)+1)//2))
    t = int(t)