while 1:
    try:
        x,y=map(int,input().split())
    except:
        break
    print("%.2f"%(x/y))