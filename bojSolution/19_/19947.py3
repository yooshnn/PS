from sys import stdin
from math import floor
input = stdin.readline

h, y = map(int, input().split())
r = [h, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for i in range(1, y + 1):
    r[i] = max(r[i], floor(r[i - 1] * 1.05))
    if i >= 3:
        r[i] = max(r[i], floor(r[i - 3] * 1.20))
    if i >= 5:
        r[i] = max(r[i], floor(r[i - 5] * 1.35))
print(r[y])
