import sys; input = sys.stdin.readline
from collections import *

n = int(input())
s = sorted([*map(int, input().split())], reverse=True)

res = 0
d = deque()

for i in s:
    if d and d[0]>i:
        d.popleft()
        d.append(i)
    else:
        d.append(i)
        res += 1

print(res)