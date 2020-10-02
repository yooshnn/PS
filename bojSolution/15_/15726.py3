from sys import stdin
x,y,z=map(int,stdin.readline().split())
print(int(max(x*y/z,x/y*z)))
