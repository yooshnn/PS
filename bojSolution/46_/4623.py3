while 1:
    a,b,c,d=map(int,input().split())
    if a==0 and b==0 and c==0 and d==0:
        break
    if b>a:t=b;b=a;a=t
    if d>c:t=d;d=c;c=t
    r=min(c/a,d/b)
    print(int(min(100,100*r)),end="%\n")