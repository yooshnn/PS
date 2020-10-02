from sys import stdin
def input(): return stdin.readline().rstrip()

a,b,c=map(int,input().split())
a=abs(a)
b=abs(b)
if a+b>c:
    print("NO")
else:
    if a+b==c or (c-(a+b))%2==0:
        print("YES")
    else:
        print("NO")