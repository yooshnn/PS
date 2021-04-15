import sys; input = sys.stdin.readline

d = {0: 32, 1: 16, 2: 8, 4: 4, 8: 2, 16: 1}

n = int(input())
res = 0
s = [*map(int, input().split())]

for i in s:
    res += d[i]

print(res/16)