from sys import stdin
A,B=map(int,stdin.readline().split())
C=int(stdin.readline())
if A+B>=C*2:
    print(A+B-C*2)
else:
    print(A+B)