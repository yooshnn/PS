from sys import stdin
while True:
    a,b,c = map(int,stdin.readline().split())
    if b==0:
        break
    res = (c-a)/b
    if res>0 and res%1==0:
        print(int(res)+1)
    else:
        print("X")