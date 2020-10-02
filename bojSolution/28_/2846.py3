l=int(input())
m=n=0
s=list(map(int,input().split()))
for i in range(1,l):
    if s[i-1]<s[i]:
        n+=s[i]-s[i-1]
    else:
        m=max(m,n)
        n=0
print(max(m,n))