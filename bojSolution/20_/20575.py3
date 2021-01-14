import sys; input = sys.stdin.readline
import math

n = int(input())
c = 0

for _ in range(n):
    t = [*map(float, input().split())]
    if math.floor(t[0])!=math.floor(t[2]):
        c += 1

print(2/(c/n))
