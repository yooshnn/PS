from sys import stdin
A=list(map(int,stdin.readline().split()))
B=list(map(int,stdin.readline().split()))
print(min(A[0]+B[1],A[1]+B[0]))