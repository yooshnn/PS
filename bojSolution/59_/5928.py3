d,h,m=map(int,input().split())
if d==11:
    if h<11 or h==11 and m<11:
        print(-1)
    else:
        print(d*24*60+h*60+m-(11*24*60+11*60+11))
else:
    print(d*24*60+h*60+m-(11*24*60+11*60+11))