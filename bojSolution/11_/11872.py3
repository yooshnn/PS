import sys
input = sys.stdin.readline

input()
r = 0
for c in [*map(int, input().split())]:
    if c==0:
        t = 0
    elif c%4 == 3:
        t = c+1
    elif c%4 == 0:
        t = c-1
    else:
        t = c
    r = r^t

print(["cubelover","koosaga"][r!=0])