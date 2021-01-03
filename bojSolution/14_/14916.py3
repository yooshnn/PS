import sys; input = sys.stdin.readline

n = int(input())
r = 0

if n&1:
    if n<5:
        print(-1); sys.exit(0)
    r += 1+2*((n-5)//10)
    n -= 5*r
    while n>0:
        n -= 2
        r += 1
    print(r)
else:
    r += 2*(n//10)
    n -= 5*r
    while n>0:
        n -= 2
        r += 1
    print(r)
