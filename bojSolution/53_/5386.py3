import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n, k = map(int, input().split())

    if k&1:
        if n&1: print(1)
        else: print(0)
    else:
        n %= k+1
        if n==k: print(n)
        elif n&1: print(1)
        else: print(0)
