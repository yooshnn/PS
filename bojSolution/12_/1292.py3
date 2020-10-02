from sys import stdin
a,b=map(int,stdin.readline().split())
li=[0]
no=1
nosub=1
for i in range(b):
    if nosub>0:
        li.append(no)
        nosub -= 1
    else:
        no+=1
        nosub=no-1
        li.append(no)
print(sum(li[a:]))