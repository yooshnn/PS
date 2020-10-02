from sys import stdin
import math
a,p1=map(int,stdin.readline().split())
r,p2=map(int,stdin.readline().split())
if a/p1 < r*r*math.pi/p2:
    print("Whole pizza")
else:
    print("Slice of pizza")
