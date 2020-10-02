s=input()
t=int(input())
li=[]
for _ in range(t):
    z=input()
    flag=True
    for i in range(len(s)):
        if s[i]=='*':continue
        if s[i]!=z[i]:flag=False
    if flag:li.append(z)
print(len(li))
if len(li)>0:
    for i in li:
        print(i)
