import sys
import math
input = sys.stdin.readline

z=0
while 1:
    z+=1
    a, b, c = map(float, input().split())
    if b==0: break
    dist = a*math.pi*b/63360
    mph = 3600*dist/c
    print("Trip #%d: %.2f %.2f"%(z,dist, mph))