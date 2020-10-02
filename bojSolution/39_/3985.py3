from sys import stdin
L=int(stdin.readline())
N=int(stdin.readline())
cake=[1]*L
hopemax=0
hopemaxer=0
scoremax=0
scoremaxer=0

for _ in range(N):
    x,y=map(int,stdin.readline().split())
    if y-x+1 > hopemax:
        hopemax=y-x+1
        hopemaxer=_
    score=cake[x-1:y].count(1)
    if score > scoremax:
        scoremax=score
        scoremaxer=_
    for QW in range(x-1,y):
        cake[QW]=0
print(hopemaxer+1,scoremaxer+1)
