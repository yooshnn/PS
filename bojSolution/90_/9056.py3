from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    x,y=stdin.readline().split()
    x=sorted(x)
    y=sorted(set(y))
    print(["NO","YES"][x==y])