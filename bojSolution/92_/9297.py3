for _ in range(int(input())):
    a,b=map(int,input().split())
    if a%b==0:print("Case ",_+1,": ",a//b,sep="")
    elif a//b==0:print("Case ",_+1,": ",a%b,"/",b,sep="")
    else:print("Case ",_+1,": ",a//b," ",a%b,"/",b,sep="")