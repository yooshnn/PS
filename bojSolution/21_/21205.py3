import sys; input = sys.stdin.readline
import fractions

realInf = [0, 0, 0]
realPart = 0
fakeInf = [0, 0, 0]
fakePart = 0

n = int(input())
for i in range(n):
    s = input()
    if s[0]=="Y":
        realPart += 1
        realInf[0] += (s[1]=="Y")
        realInf[1] += (s[2]=="Y")
        realInf[2] += (s[3]=="Y")
    else:
        fakePart += 1
        fakeInf[0] += (s[1]=="Y")
        fakeInf[1] += (s[2]=="Y")
        fakeInf[2] += (s[3]=="Y")

realA = fractions.Fraction(realInf[0], realPart)
realB = fractions.Fraction(realInf[1], realPart)
realC = fractions.Fraction(realInf[2], realPart)
fakeA = fractions.Fraction(fakeInf[0], fakePart)
fakeB = fractions.Fraction(fakeInf[1], fakePart)
fakeC = fractions.Fraction(fakeInf[2], fakePart)

if realA>=fakeA: print("Not Effective")
else: print(100-100*float(realA / fakeA))
if realB>=fakeB: print("Not Effective")
else: print(100-100*float(realB / fakeB))
if realC>=fakeC: print("Not Effective")
else: print(100-100*float(realC / fakeC))