import sys
import collections
input = sys.stdin.readline
deque = collections.deque

n = int(input())
d = deque()
for i in range(n):
    d.append(int(input()))

cur = -1
res = 0
while d:
    c = d.pop()
    if c>cur:
        cur = c
        res += 1

print(res)