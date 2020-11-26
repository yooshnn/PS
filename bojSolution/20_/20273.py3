import sys
import math
input = sys.stdin.readline

for TEST in range(int(input())):
    l, r = map(int, input().split())
    res = math.pi * math.sqrt(r*r - l*l)/2 * r/2
    print(int(round(res, -2)))