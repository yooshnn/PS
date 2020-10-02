from sys import stdin
n=int(stdin.readline())
v=n//2
h=n-v
v+=1
h+=1
print(v*h)