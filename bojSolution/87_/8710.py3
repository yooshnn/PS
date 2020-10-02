k,w,m=map(int,input().split())
if k>=w:
    print(0)
else:
    w-=k+1
    print(w//m+1)