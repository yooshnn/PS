x,y,z=map(int,input().split())
a=max(y,x-y)
b=max(z,x-z)
print(a*b*4)
