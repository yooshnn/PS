import sys; input = sys.stdin.readline

s = [*map(float, input().split())]
avg = sum(s)/10
d = 0

for i in range(10):
    d += (s[i]-avg)**2

if d/9 > 1: print("NOT COMFY")
else: print("COMFY")