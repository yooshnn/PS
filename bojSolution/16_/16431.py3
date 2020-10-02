from sys import stdin
B=list(map(int,stdin.readline().split()))
D=list(map(int,stdin.readline().split()))
J=list(map(int,stdin.readline().split()))
dtime=abs(J[0]-D[0])+abs(J[1]-D[1])
btime=0
while B[0]!=J[0] or B[1]!=J[1]:
    if J[0]>B[0]:
        B[0]+=1
    if J[0]<B[0]:
        B[0]-=1
    if J[1]>B[1]:
        B[1]+=1
    if J[1]<B[1]:
        B[1]-=1
    btime+=1
if dtime < btime:
    print("daisy")
elif btime < dtime:
    print("bessie")
else:
    print("tie")