a=list(map(int,input().split()))
b=list(map(int,input().split()))

x=b[0]-a[0]
if a[1]>b[1] or (a[1]==b[1] and a[2]>b[2]):
    x-=1

y=b[0]-a[0]+1

print(x,y,y-1,sep="\n")