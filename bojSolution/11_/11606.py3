from sys import stdin
n,k=map(int,stdin.readline().split())

saf=[1]
bre=[k]
for _ in range(n):
    flr,sf=stdin.readline().split()
    flr=int(flr)
    if sf=="SAFE":
        saf.append(flr)
    else:
        bre.append(flr)
saf=sorted(saf)
bre=sorted(bre)
if bre[0] - saf[-1] > 1:
    print(saf[-1]+1,bre[0]-1)
else:
    print(bre[0],saf[-1])
