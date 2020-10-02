from sys import stdin
res=1
temp=1
T=int(stdin.readline())
arr=[int(x) for x in stdin.readline().split()]
if T>1:
    for i in range(1,T):
        if arr[i]>=arr[i-1]:
            temp+=1
        else:
            res=max(res,temp)
            temp=1
print(max(res,temp))