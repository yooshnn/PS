li=list(map(int,input().split()))
a=[ sorted([li[0],li[2]]), sorted([li[1],li[3]]) ]
li=list(map(int,input().split()))
b=[ sorted([li[0],li[2]]), sorted([li[1],li[3]]) ]

newx=[]
newy=[]
newx.append(max(a[0][0],b[0][0]))
newx.append(min(a[0][1],b[0][1]))
newy.append(max(a[1][0],b[1][0]))
newy.append(min(a[1][1],b[1][1]))
#newx=sorted(newx)
#newy=sorted(newy)
w=newx[1]-newx[0]
h=newy[1]-newy[0]
if w<0 or h<0:
    print(0)
else:
    print(max(0,w*h))
