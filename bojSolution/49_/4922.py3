from sys import stdin
while True:
    n=int(stdin.readline())
    if n==0: break
    r=1
    for i in range(n):
        r+=2*i
    print(n,"=>",r)
