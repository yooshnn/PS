N=int(input())
li=[]
res=0
for _ in range(N):
    x,y=map(int,input().split())
    li.append(list([x,y]))
li=sorted(li)
for i in li:
    if i[0]<res:
        res+=i[1]
    else:
        res=sum(i)
print(res)