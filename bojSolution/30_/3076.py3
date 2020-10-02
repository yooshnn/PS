from sys import stdin
def input(): return stdin.readline().rstrip()
r,c=map(int,input().split())
a,b=map(int,input().split())
r*=a
c*=b
for i in range(r):
    for j in range(c):
        if ((i//a)+(j//b))%2==1:
            print(".",end="")
        else:
            print("X",end="")
    print()