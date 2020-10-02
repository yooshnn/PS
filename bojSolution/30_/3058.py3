T=int(input())
for _ in range(T):
    first=1
    res=0
    li=sorted(list(map(int,input().split())))
    for i in li:
        if i%2==0:
            if first==1:
                first=i
            res+=i
    print(res,first)