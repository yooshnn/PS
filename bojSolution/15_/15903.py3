import sys; input = sys.stdin.readline
import heapq

n, m = map(int, input().split())
s = [*map(int, input().split())]
heapq.heapify(s)

for i in range(m):
    a, b = heapq.heappop(s), heapq.heappop(s)
    heapq.heappush(s, a+b)
    heapq.heappush(s, a+b)

r = 0
for i in range(n):
    r += heapq.heappop(s)

print(r)