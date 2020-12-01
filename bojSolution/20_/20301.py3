import sys
import collections
input = sys.stdin.readline
deque = collections.deque

n, k, m = map(int, input().split())
p = deque([i for i in range(1, n+1)])
r = 0

while p:
    p.rotate(-k+(1 if k>0 else 0))
    print(p.popleft())
    r += 1
    if r==m:
        r = 0
        k *= -1