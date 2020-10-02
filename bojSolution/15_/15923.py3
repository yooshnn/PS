from sys import stdin
import math
N=int(stdin.readline())
cx=cy=0
px=py=0
fx=fy=0
res=0
for i in range(N):
    if i==0:
        cx,cy=map(int,stdin.readline().split())
        fx,fy=cx,cy
    elif i==N-1:
        px,py=cx,cy
        cx,cy=map(int,stdin.readline().split())
        res+=math.sqrt((cx-px)*(cx-px)+(cy-py)*(cy-py))
        res+=math.sqrt((cx-fx)*(cx-fx)+(cy-fy)*(cy-fy))
    else:
        px,py=cx,cy
        cx,cy=map(int,stdin.readline().split())
        res+=math.sqrt((cx-px)*(cx-px)+(cy-py)*(cy-py))
print(int(res))
