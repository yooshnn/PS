import sys; input = sys.stdin.readline

N = int(input())
dup = [False for _ in range(N)]
c, res = 0, 0

while 1:
    dup[c] = True
    res = c
    c = (c + (c+1))%N
    if c==0 or dup[c]==True:
        break

print(res+1)