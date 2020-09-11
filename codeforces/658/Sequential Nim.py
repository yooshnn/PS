from sys import stdin

T=int(stdin.readline())
for _ in range(T):
    cnt=0
    N=int(stdin.readline())
    li=list(map(int,stdin.readline().split()))
    for i in li:
        if i==1:
            cnt+=1
        else:
            break

    if cnt%2==0:
        if cnt==N:
            print("Second")
        else:
            print("First")
    else:
        if cnt==N:
            print("First")
        else:
            print("Second")
