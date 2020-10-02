from decimal import getcontext, Decimal as D
getcontext().prec = 2000
res=D(1/(2**D(input())))
p = abs(res.as_tuple().exponent)
print(('{:.%df}' % p).format(res))