from sys import stdin
a,b=map(int,stdin.readline().split())
c,d=map(int,stdin.readline().split())

w=a/c+b/d
x=c/d+a/b
y=d/b+c/a
z=b/a+d/c

r=max(w,x,y,z)
if w==r:
    print(0)
elif x==r:
    print(1)
elif y==r:
    print(2)
elif z==r:
    print(3)
