import sys
input = sys.stdin.readline

while 1:
    a, b = map(int, input().split())
    if a==0 and b==0: break
    print(min(30*a+40*b, 35*a+30*b, 40*a+20*b))