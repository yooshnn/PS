from sys import stdin, stdout
rx=-1
ry=-1
x,y=map(float,stdin.readline().split())

if x==0:
    if y>=125:
        rx=250*125*1/y
        ry=0
    else:
        rx=250*125*1/(250-y)
        ry=250-250*125*1/(250-y)
elif y==0:
    if x>=125:
        rx=0
        ry=250*125*1/x
    else:
        rx=250-250*125*1/(250-x)
        ry=250*125*1/(250-x)
elif y<=125:
    rx=0
    ry=250-(250*125*1/x)
else:
    rx=250-(250*125*1/y)
    ry=0

print(format(rx,".2f"),format(ry,".2f"))
