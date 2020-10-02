l=int(input())
if l>0:
    m=list(map(int,input().split()))
if l==0:
    print("divide by zero")
else:
    if sum(m)/l==0:
        print("divide by zero")
    else:
        print("1.00")
