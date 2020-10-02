from sys import stdin
while 1:
    a,b,c,d=map(int,stdin.readline().split())
    if a==0 and b==0 and c==0 and d==0:break
    print(c-b,d-a)