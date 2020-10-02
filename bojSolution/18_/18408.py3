from sys import stdin
a=map(int,stdin.readline().split())
a=sum(a)
print([1,2][int(a>4)])