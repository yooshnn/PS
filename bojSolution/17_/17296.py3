from decimal import Decimal as D
n=int(input())
li=list(map(D,input().split()))

res=int(li[0])
res+=int(li[0]%1!=0)
for i in range(1,n):
    if li[i]%1!=0 and res==0:
        res+=1
    res+=int(li[i])
    
print(res)