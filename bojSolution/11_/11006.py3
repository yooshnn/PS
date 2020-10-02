from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    x,y=map(int,stdin.readline().split())
    print(y*2-x,y-(y*2-x))