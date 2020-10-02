from sys import stdin, stdout
r,c,n=map(int,stdin.readline().split())
print((((r-1)//n)+1) * (((c-1)//n)+1))
