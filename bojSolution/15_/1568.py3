import sys; input=sys.stdin.readline

n = int(input())
r = 0
c = 0
while n>0:
    r += 1
    c += 1
    if n>=c:
        n -= c
    else:
        c = 1
        n -= c
print(r)
