a=int(input())
res=0
for i in range(100):
    for j in range(100):
        if a-i-j==0:
            res+=1
print(res)