while True:
    a,b=map(int,input().split())
    if b<1:break
    print(a//b,a%b,"/",b)