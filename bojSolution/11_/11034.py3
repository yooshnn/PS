from sys import stdin
def input(): return stdin.readline().rstrip()
while 1:
    l=input()
    if not l: break
    a,b,c=map(int,l.split())
    res=0
    while True:
        if not (a<b and b<c): break
        abdis=b-a
        bcdis=c-b
        if abdis==1 and bcdis==1:
            break
        res+=1
        if abdis>bcdis:
            c=b-1
            t=b
            b=c
            c=t
        else:
            a=b+1
            t=b
            b=a
            a=t
    print(res)