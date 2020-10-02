for _ in range(int(input())):
    x,y,z=map(int,input().split())
    y-=z
    if x==y:print("does not matter")
    else:print(["do not ",""][x<y],"advertise",sep="")