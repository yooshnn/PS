import sys; input = sys.stdin.readline

TC = 0
while 1:
    TC += 1

    n = int(input())
    if n==0: break

    print("%d."%TC, end=" ")

    n *= 3
    print("odd" if n&1 else "even", end=" ")

    n = 3*(n+1)//2
    print(n//9)
