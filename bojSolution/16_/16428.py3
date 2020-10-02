from sys import stdin
a,b=map(int,stdin.readline().split())
if a>=0 and b>=0:
    print(a//b)
    print(a%b)
elif a>=0 and b<0:
    print("-",a//abs(b),sep="")
    print(a-(abs(b)*(a//abs(b))))
elif a<0 and b>=0:
    if a%b==0:
        print("-",abs(a)//b,sep="")
        print(0)
    else:
        print("-",1+abs(a)//b,sep="")
        print(a%b)
elif a<0 and b<0:
    if a%b==0:
        print(abs(a)//abs(b))
        print(0)
    else:
        print(1+abs(a)//abs(b))
        print(abs(a + abs(b)*(1+abs(a)//abs(b))))
