from sys import stdin
A=int(stdin.readline())
B=int(stdin.readline())
C=int(stdin.readline())
D=int(stdin.readline())
P=int(stdin.readline())
res1=res2=0
res1=A*P
if P<=C:
    res2=B
else:
    res2=B+(P-C)*D
print(min(res1,res2))