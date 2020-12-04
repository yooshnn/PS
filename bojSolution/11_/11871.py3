import sys
input = sys.stdin.readline

N = int(input())
s = [*map(int, input().split())]
r = 0

for c in s:
    if c&1:
        r ^= (c+1)//2
    else:
        r ^= (c-2)//2
print(["koosaga", "cubelover"][r==0])