g=int(input())
l=list(map(int,input().split()))
res=0
for i in range(g):
    if i+1 != l[i]:
        res+=1
print(res)