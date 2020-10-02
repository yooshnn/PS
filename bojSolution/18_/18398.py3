from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    for __ in range(int(input())):
        x,y=map(int,input().split())
        print(x+y,x*y)