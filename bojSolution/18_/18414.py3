from sys import stdin
x,l,r = map(int,stdin.readline().split())
if x<l:
    print(l)
elif x>r:
    print(r)
else:
    print(x)