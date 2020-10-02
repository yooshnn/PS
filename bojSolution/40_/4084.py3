from sys import stdin
def input(): return stdin.readline().strip()

while True:
    a,b,c,d=map(int,input().split())
    if a==0: break
    res=0
    while a!=b or a!=c or a!=d:
        res+=1
        a,b,c,d=abs(a-b),abs(b-c),abs(c-d),abs(d-a)
    print(res)
