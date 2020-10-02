from sys import stdin
a,b=map(int,stdin.readline().split())
c=max(a,b)*2
if c<1:
    print("Not a moose")
else:
    print(["Odd","Even"][a==b],c,sep=" ")