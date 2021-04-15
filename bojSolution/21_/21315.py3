import sys; input = sys.stdin.readline
from collections import *

def shuf(card: deque, k: int):
    ret = deque()
    draw = deque()
    for it in range(k, -1, -1):
        for i in range(2**it):
            draw.appendleft(card.pop())
        while card:
            ret.appendleft(card.pop())
        while draw:
            card.appendleft(draw.pop())
    while card:
        ret.appendleft(card.pop())
    return ret

n = int(input())
org = [i for i in range(1, n+1)]
res = [*map(int, input().split())]

lim = 1
while 2**lim<n:
    lim += 1

for i in range(1, lim):
    firstShuffle = shuf(deque([i for i in org]), i)
    for j in range(1, lim):
        secondShuffle = shuf(deque([i for i in firstShuffle]), j)
        if all(res[k]==secondShuffle[k] for k in range(n)):
            print(i, j)
            sys.exit(0)