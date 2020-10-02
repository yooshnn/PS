from sys import stdin
L=int(stdin.readline())
A=sorted(map(int,stdin.readline().split()))
B=sorted(map(int,stdin.readline().split()),reverse=True)
for _ in range(L):
    A[_]*=B[_]
print(sum(A))