from decimal import Decimal as D
k=D(input())
a,b=map(D,input().split())
print(k*k-((a-b)/2)**2)