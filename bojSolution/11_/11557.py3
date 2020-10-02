from sys import stdin

a=[]
d={}

T=int(stdin.readline())
for _ in range(T):
    N=int(stdin.readline())
    del a[:]
    d.clear()
    for i in range(N):
        un,sm=stdin.readline().split()
        a.append(int(sm))
        d[sm]=un
    a=sorted(a)
    print(d[str(a[-1])])