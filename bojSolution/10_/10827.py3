from decimal import getcontext, Decimal as D
getcontext().prec = 3000
a, b = map(D, input().split())
res=D(a**b)
p = abs(res.as_tuple().exponent)
print(('{:.%df}' % p).format(res))