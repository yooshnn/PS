a=list(map(int,input().split()))
b=list(map(int,input().split()))

c=max(a[0],a[2],b[0],b[2])-min(a[0],a[2],b[0],b[2])
d=max(a[1],a[3],b[1],b[3])-min(a[1],a[3],b[1],b[3])
print(max(c,d)**2)