for _ in range(int(input())):
    n=input()
    s=sum(map(int,input().split()))
    if s==0:print("Equilibrium")
    else:print("Left"if s<0else"Right")