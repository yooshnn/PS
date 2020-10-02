from sys import stdin

ax,ay = map(int, input().split())
bx,by = map(int, input().split())
cx,cy = map(int, input().split())

rx = ax
ry = ay

if rx == bx:
    rx = cx
elif rx == cx:
    rx = bx

if ry == by:
    ry = cy
elif ry == cy:
    ry = by

print(rx, end=" ")
print(ry)