from sys import stdin

E,S,M=map(int,stdin.readline().split())
res=0

while True:
    res+=1
    if (res-E)%15 + (res-S)%28 + (res-M)%19 == 0:
        print(res)
        break