from sys import stdin
L=int(stdin.readline())
A=int(stdin.readline())
B=int(stdin.readline())
C=int(stdin.readline())
D=int(stdin.readline())
print(L-max((A-1)//C+1,(B-1)//D+1))