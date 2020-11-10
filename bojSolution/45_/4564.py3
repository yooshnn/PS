import sys
input = sys.stdin.readline

while 1:
    n = int(input())
    if n==0: break
    while 1:
        print(n, end=" ")
        if n<10: break

        r = 1
        n = str(n)
        for c in n:
            r *= int(c)
        n = r
    print()