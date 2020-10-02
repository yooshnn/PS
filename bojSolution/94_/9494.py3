while 1:
    z=int(input())
    if z==0:break
    li=[]
    for _ in range(z):
        li.append(input()+" ")
    p=0
    for i in li:
        if len(i)>p:
            p=i.find(" ",p)
    print(p+1)