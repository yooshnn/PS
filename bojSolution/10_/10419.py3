from math import sqrt,floor
for _ in range(int(input())):
    n=int(input())
    x=0
    for i in range(0,101):
        if i+(i*i)<=n: x=i
        else: break
    print(x)