from sys import stdin
m=int(stdin.readline())
d=int(stdin.readline())
if m<2:
    print("Before")
elif m>2:
    print("After")
else:
    if d==18:
        print("Special")
    elif d<18:
        print("Before")
    else:
        print("After")