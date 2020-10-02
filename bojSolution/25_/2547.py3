from sys import stdin
li=[]
T=int(stdin.readline())
for _ in range(T):
    garb=stdin.readline()
    n=int(stdin.readline())
    del li[:]
    for i in range(n):
        li.append(int(stdin.readline()))
    if sum(li)%len(li)==0:
        print("YES")
    else:
        print("NO")
