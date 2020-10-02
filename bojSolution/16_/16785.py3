from sys import stdin
a,b,c=map(int,stdin.readline().split())
for i in range(1, c+1):
    if c<=(a*i + b*(i//7)):
        print(i)
        break
