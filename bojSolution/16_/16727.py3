li=list(map(int,input().split()))
x,y=map(int,input().split())
li.append(x)
li.append(y)
if li[0]+li[3]>li[1]+li[2]:
    print("Persepolis")
elif li[0]+li[3]<li[1]+li[2]:
    print("Esteghlal")
else:
    if li[1]==li[3]:
        print("Penalty")
    else:
        if li[1]<li[3]:
            print("Persepolis")
        else:
            print("Esteghlal")
