from sys import stdin

m=stdin.readline().strip()
n=int(stdin.readline())

honeyjamlist=[]

for _ in range(n):
    ishoneyjam=False
    honeyjam=list(m)[::-1]
    w,g=stdin.readline().split()
    wsave=w
    w=list(str(w))[::-1]
    g=int(g)
    for i in range(len(m)):
        while len(w)>0:
            if honeyjam[-1]==w.pop():
                honeyjam.pop()
            if len(honeyjam)==0:
                w.clear()
                ishoneyjam=True
                break
    if ishoneyjam:
        honeyjamlist.append(list([g/(len(wsave)-len(m)),wsave]))
if len(honeyjamlist)==0:
    print("No Jam")
else:
    maxl=0
    maxw=""
    for elem in honeyjamlist:
        if elem[0]>maxl:
            maxl=elem[0]
            maxw=elem[1]
    print(maxw)
