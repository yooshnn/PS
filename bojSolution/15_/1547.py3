from sys import stdin
T=int(stdin.readline())
cur=1
for _ in range(T):
    x,y=map(int,stdin.readline().split())
    if x==cur:
        cur=y
    elif y==cur:
        cur=x
print(cur)