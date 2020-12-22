import sys; input = sys.stdin.readline
from decimal import Decimal as D

def puts(*s):
    for c in list(s):
        c = str(c)
        if len(c)<10:
            c = " "*(10-len(c)) + c
        print(c, end="")

TEST = int(input())
year = 1994
ma, fa, mf, ff, mn, fn = D(1703), D(3714), D(686), D(640), D(1372), D(1280)

print("""         HERD     ADULT     ADULT     MALE     FEMALE     MALE     FEMALE
YEAR     SIZE     MALES    FEMALES    FAWNS     FAWNS    NEWBORN   NEWBORN
----   -------   -------   -------   -------   -------   -------   -------""")
for i in range(TEST):
    print(year, end="")
    puts(ma+fa+mf+ff+mn+fn, ma, fa, mf+mn, ff+fn, mn, fn)

    ft = fa
    ma = ((15*ma+60*mf+50)//100)
    fa = ((90*fa+60*ff+50)//100)
    mf = ((55*mn+50)//100)
    ff = ((55*fn+50)//100)
    mn = ((52*150*ft+5000)//10000)
    fn = ((48*150*ft+5000)//10000)
    year += 1
    if i!=TEST-1: print()
