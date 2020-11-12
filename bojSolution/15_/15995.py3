import sys
input = sys.stdin.readline

a, m = map(int, input().split())

x = 1
while 1:
    if (a*x)%m == 1:
        print(x)
        break
    x+=1