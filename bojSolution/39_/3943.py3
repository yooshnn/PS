import sys; input = sys.stdin.readline
for TEST in range(int(input())):
    n = int(input())
    r = n
    while n!=1:
        r = max(r, n)
        if n&1: n = 3*n + 1
        else: n = n//2
    print(r)