from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s=list(map(int,input().split()))
    hp=max(1,s[0]+s[4])
    mp=max(1,s[1]+s[5])
    at=max(0,s[2]+s[6])
    df=s[3]+s[7]
    print(hp+5*mp+2*at+2*df)