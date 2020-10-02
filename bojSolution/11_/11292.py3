from sys import stdin
li=[]
while True:
    N=int(stdin.readline())
    if N==0:
        break
    del li[:]
    for _ in range(N):
        x,y=stdin.readline().split()
        y=float(y)
        li.append(list([y,x]))
    co=sorted(li)
    for i in li:
        if i[0]==co[N-1][0]:
            print(i[1],end=" ")
    print()