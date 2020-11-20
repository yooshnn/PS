import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a = [*map(int, input().split())]
    b = [*map(int, input().split())]

    p = a[0] + a[1]*2 + (a[2]+a[3])*3 + a[4]*4 + a[5]*10
    q = b[0] + (b[1]+b[2]+b[3])*2 + b[4]*3 + b[5]*5 + b[6]*10

    print("Battle %d: "%(_+1), end="")
    if p>q:
        print("Good triumphs over Evil")
    elif p<q:
        print("Evil eradicates all trace of Good")
    else:
        print("No victor on this battle field")