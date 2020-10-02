from decimal import Decimal as D
from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    xl=yr=2000
    xr=yl=-2000
    for i in range(int(input())):
        x,y=map(D,input().split())
        if x<xl: xl=x
        if y<yr: yr=y
        if x>xr: xr=x
        if y>yl: yl=y
    print("Case ",_+1,": Area ",abs(xr-xl)*abs(yr-yl),", Perimeter ",2*(abs(xr-xl)+abs(yr-yl)),sep="")