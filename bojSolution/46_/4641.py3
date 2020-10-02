from sys import stdin
while True:
    s=list(map(int,stdin.readline().split()))
    res=0
    if s[0]==-1:
        break
    for i in s:
        if i==0:
            break
        if i*2 in s:
            res+=1
    print(res)