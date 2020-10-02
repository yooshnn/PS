import sys
n,x=sys.stdin.readline().split()
x=int(x)
a=sys.stdin.readline().split()
a=map(int,a)
for item in a:
    if item < x:
        print(item, end=" ")