from sys import stdin
from queue import PriorityQueue
def input(): return stdin.readline().rstrip()

q = PriorityQueue()

t = int(input())
c = int(input())
for _ in range(c):
    q.put(int(input()))

r = 0
res = 0
while not q.empty():
    cur = q.get()
    if r + cur <= t:
        r += cur
        res += 1
    else:
        break

print(res)