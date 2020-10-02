li=[]
res=0
for _ in range(3):
    x,y=map(int,input().split())
    li.append([x,y])
for i in range(3):
    res+=li[i][0]*(li[(i+1)%3][1]-li[(i+2)%3][1])
print(["WINNER WINNER CHICKEN DINNER!","WHERE IS MY CHICKEN?"][res==0])
