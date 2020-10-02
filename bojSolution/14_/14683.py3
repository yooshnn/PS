from sys import stdin
def input(): return stdin.readline().rstrip()

a, b = map(int, input().split())
c, d = map(int, input().split())
t = int(input())

a = abs(c - a)
b = abs(d - b)

if a+b>t:
    print("N")
else:
    if a+b==t or (t-(a+b))%2==0:
        print("Y")
    else:
        print("N")
