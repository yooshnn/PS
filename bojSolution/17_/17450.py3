from sys import stdin
def input(): return stdin.readline().rstrip()

a,b=map(int,input().split())
gs=(b*10)/(a*10-(500*int(a*10>=5000)))
a,b=map(int,input().split())
gn=(b*10)/(a*10-(500*int(a*10>=5000)))
a,b=map(int,input().split())
gu=(b*10)/(a*10-(500*int(a*10>=5000)))
if gs>gn and gs>gu:
    print("S")
if gn>gs and gn>gu:
    print("N")
if gu>gs and gu>gn:
    print("U")