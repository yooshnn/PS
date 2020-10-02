from sys import stdin
C=[True]*31
C[0]=False
for i in range(28):
    x=int(stdin.readline())
    C[x]=False
for i in range(31):
    if C[i]:
        print(i)