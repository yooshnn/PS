from sys import stdin
for _ in range(int(input())):
    a,b=map(int,stdin.readline().split())
    apos=True if a>0 else False
    bpos=True if b>0 else False

    a=abs(a)
    b=abs(b)

    tob=(b*(b+1))//2
    toa=(a*(a+1))//2

    print("Scenario #",_+1,":",sep="")
    if apos and bpos:
        print(tob-toa+a)
    elif not apos and bpos:
        print(tob-toa)
    elif not apos and not bpos:
        print(-toa+tob-b)
    print()
