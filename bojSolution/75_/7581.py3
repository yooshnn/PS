while 1:
    a,b,c,d=map(int,input().split())
    if a==0 and b==0 and c==0 and d==0:
        break
    if a==0:
        print(int(d/(b*c)),b,c,d)
    elif b==0:
        print(a,int(d/(a*c)),c,d)
    elif c==0:
        print(a,b,int(d/(a*b)),d)
    elif d==0:
        print(a,b,c,a*b*c)