from sys import stdin

while True:
    a,b=map(int,stdin.readline().split())
    if a==b and a==0:
        break
    if a>b:
        if a%b==0:
            print("multiple")
        else:
            print("neither")
    else:
        if b%a==0:
            print("factor")
        else:
            print("neither")