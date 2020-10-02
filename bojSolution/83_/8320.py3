n=int(input())
r=0
for i in range(1,n+1):
    for j in range(i,n//i+1):
        r+=1
print(r)