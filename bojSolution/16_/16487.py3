from decimal import Decimal as D

a,b,c=map(D,input().split())
m=D(input())

top=D((b-m)*a*a+m*c*c)
bottom=D(b)
right=D((b-m)*m)
print(D(D(top/bottom)-right))
