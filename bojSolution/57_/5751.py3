while True:
    t=int(input())
    if t==0:break
    l=list(map(int,input().split()))
    j=sum(l)
    print("Mary won",t-j,"times and John won",j,"times")