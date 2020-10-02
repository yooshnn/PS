from sys import stdin
import math
d,h,w=map(int,stdin.readline().split())
a=math.sqrt((d**2)/(1+(h**2)/(w**2)))
b=math.sqrt((d**2)/(1+(w**2)/(h**2)))
w=a
h=b
print(math.floor(h),math.floor(w))