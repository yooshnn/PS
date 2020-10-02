from sys import stdin
res=0
cnt=0
T=int(stdin.readline())
a=[int(x) for x in stdin.readline().split()]
for i in range(T):
    if a[i]==cnt+1:
        cnt=a[i]
    else:
        res+=1
print(res)
