import sys; input = sys.stdin.readline
from collections import *

while 1:
    n = int(input())
    if n==0: break
    s = sorted([int(input()) for i in range(n)], reverse=True)

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
