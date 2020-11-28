import sys
input = sys.stdin.readline

res, b, c, d, e = map(int, input().split())
debug = 0
while b>0:
    if e>0:
        res += min(b, e)
        b, e = b-min(b, e), e-min(b, e)
    else:
        res += b
        b = 0
if debug: print(res, b, c, d, e)
while c>0:
    if d>0:
        res += min(c, d)
        c, d = c-min(c, d), d-min(c, d)
    elif e>0:
        res += min(c, 1+(e-1)//2)
        c, e = c-min(c, 1+(e-1)//2), e-2*min(c, 1+(e-1)//2)
    else:
        res += c
        c = 0
if debug: print(res, b, c, d, e)
while d>0:
    if e>0:
        if d>=2:
            d -= 2
            e -= 1
        else:
            d -= 1
            e -= 3
        res += 1
    else:
        res += 1+(d-1)//2
        d = 0
if debug: print(res, b, c, d, e)
if e>0:
    res += 1+(e-1)//5
if debug: print(res, b, c, d, e)

print(res)
