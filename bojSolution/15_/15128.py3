from decimal import Decimal as D
a,b,c,d=map(D,input().split())
print(int(D(0.5)*D(a*c/b/d)%1==0))