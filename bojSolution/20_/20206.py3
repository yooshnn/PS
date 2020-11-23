import sys
input = sys.stdin.readline

A, B, C = map(int, input().split())
x1, x2, y1, y2 = map(int, input().split())
good = True

if A==0: # By + C = 0, y = -C/B
    if y1 < -C/B < y2:
        good = False
elif B==0: # Ax + C = 0, x = -C/A
    if x1 < -C/A < x2:
        good = False
else: # Ax + By + C = 0, By = -Ax - C, y = -(Ax + C)/B, x = -(By + C)/A
    if y1 < -(A*x1 + C)/B < y2 or y1 < -(A*x2 + C)/B < y2:
        good = False
    if x1 < -(B*y1 + C)/A < x2 or x1 < -(B*y2 + C)/A < x2:
        good = False

print("Lucky" if good else "Poor")