import sys; input = sys.stdin.readline
import math

def calc(w, h):
    return w*w + h*h

m = []

N = int(input())
for i in range(N):
    m.append((-calc(*map(int, input().split())), i+1))

for i in sorted(m):
    print(i[1])