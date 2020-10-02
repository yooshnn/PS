from sys import stdin
h,m,s=map(int,stdin.readline().split())
time=int(stdin.readline())
s+=time
m+=s//60
s%=60
h+=m//60
m%=60
h%=24
print(h,m,s)