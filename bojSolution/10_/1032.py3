from sys import stdin
N=int(stdin.readline())
F=list(stdin.readline()[:-1])
for _ in range(N-1):
    temp=list(stdin.readline()[:-1])
    for i in range(len(F)):
        if F[i]!=temp[i]:
            F[i]="?"
print(*F,sep="")