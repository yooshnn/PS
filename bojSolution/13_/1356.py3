n=input()
flag=False
for i in range(1,len(n)):
    x=n[:i]
    y=n[i:]
    xx=1
    yy=1
    for j in x:
        xx*=int(j)
    for j in y:
        yy*=int(j)
    if xx==yy:flag=True
print(["NO","YES"][flag])