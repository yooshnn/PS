N=int(input())
d={}
res=0

for _ in range(N):
    x,y=map(int,input().split())
    try:
        if d[x]!=y:
            d[x]=y
            res+=1
    except:
        d[x]=y
print(res)
