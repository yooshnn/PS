from sys import stdin
while True:
    li=list(map(int,stdin.readline().split()))
    if li[0]==0:
        break
    li=li[1:]
    res=li[0]-li[1]
    for i in range(2,len(li)):
        if i%2==0:
            res*=li[i]
        else:
            res-=li[i]
    print(res)
