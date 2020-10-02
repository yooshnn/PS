from decimal import getcontext, Decimal
getcontext().prec = 1500
a, b= map(Decimal, input().split())
print(a/b)