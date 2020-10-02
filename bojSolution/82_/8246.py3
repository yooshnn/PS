a,b,k=map(int,input().split())
if a//k==0 or b//k==0:
    print(0)
elif a//k==1 and b//k==1:
    print(1)
elif a//k==1:
    print(b//k)
elif b//k==1:
    print(a//k)
else:
    print(a//k*2 + (b//k-2)*2)