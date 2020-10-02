while True:
    a,b,c=map(int,input().split())
    if a==0 and b==0 and c==0:
        break
    if c-b==b-a:
        t=c-b
        print("AP",c+t)
    else:
        t=b/a
        print("GP",int(c*t))