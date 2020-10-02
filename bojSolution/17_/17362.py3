from sys import stdin
a=int(stdin.readline())
if a<=5:
    print(a)
else:
    t=a-5
    t%=4
    if ((a-5)//4)%2==0:
        print(5-t)
    else:
        print(t+1)