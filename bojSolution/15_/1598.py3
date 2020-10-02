from sys import stdin
x,y=map(int,stdin.readline().split())
xr=(x-1)%4
xc=(x-1)//4
yr=(y-1)%4
yc=(y-1)//4
rd=abs(xr-yr)
cd=abs(xc-yc)
print(rd+cd)
