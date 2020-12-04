import sys
import collections
input = sys.stdin.readline
deque = collections.deque

class Circle:
    def __init__(self):
        self.x, self.y, self.r = map(float, input().split())
        self.dup = False

def overlap(a: Circle, b: Circle):
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=(a.r+b.r)*(a.r+b.r))

result = []

for TEST in range(int(input())):
    Y, X, N = map(int, input().split())

    crater, que = set(), deque()

    for _ in range(N):
        crat = Circle()
        if crat.y <= crat.r:
            que.append(crat)
            crat.dup = True
        else:
            crater.add(crat)

    crossable = True
    while que:
        crat = que.pop()
        if crat.y+crat.r>=Y:
            crossable = False
            break
        next = []
        for it in crater:
            if overlap(crat, it):
                it.dup = True
                next.append(it)
        for it in next:
            crater.remove(it)
            que.append(it)
    result.append("Case %d: %s"%(TEST+1, "Clear To Go" if crossable else "Find Another Path"))

print("\n".join(result))