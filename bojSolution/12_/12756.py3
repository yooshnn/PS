from sys import stdin
x,y=map(int,stdin.readline().split())
a,b=map(int,stdin.readline().split())

od=False
sd=False

while True:
    y-=a
    b-=x
    if y<=0:
        od=True
    if b<=0:
        sd=True
    if od or sd:
        break

if od and sd:
    print("DRAW")
elif od:
    print("PLAYER B")
else:
    print("PLAYER A")
