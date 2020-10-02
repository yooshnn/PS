from sys import stdin, stdout
T=int(stdin.readline())
for _ in range(T):
    err=False
    func=stdin.readline()[:-1].replace("RR","")
    llen=int(stdin.readline())
    if llen==0:
        stdin.readline()
        li=[]
    else:
        li=stdin.readline()[1:-2].split(",")

    direction=1
    l=0
    r=0
    for f in func:
        if f=="R":
            direction *= -1
        elif f=="D":
            if direction==1:
                l+=1
            else:
                r+=1
    if l+r<=llen:
        if direction==1:
            li=li[l:llen-r]
        if direction==-1:
            li=li[l:llen-r][::-1]
    else:
        err=True

    if err==True:
        print("error")
    else:
        print("[",end="")
        print(",".join(li),end="")
        print("]")
