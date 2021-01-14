import sys; input = sys.stdin.readline

a, b, c, d = map(int, input().split())
Q, W, E = map(int, input().split())
r0, r1, r2 = 0, 0, 0

barkingA, barkingB = False, False
coolA, coolB = 0, 0

for i in range(1, 1001):

    if coolA>0:
        coolA -= 1
    if coolA==0:
        if barkingA:
            barkingA = False
            coolA = b
        else:
            barkingA = True
            coolA = a
    if coolB>0:
        coolB -= 1
    if coolB==0:
        if barkingB:
            barkingB = False
            coolB = d
        else:
            barkingB = True
            coolB = c

    if i==Q:
        r0 = (barkingA + barkingB)
    if i==W:
        r1 = (barkingA + barkingB)
    if i==E:
        r2 = (barkingA + barkingB)






print(r0, r1, r2)
