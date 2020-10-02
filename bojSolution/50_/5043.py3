from sys import stdin
r=1
a,b=map(int,stdin.readline().split())
for i in range(b):
    r+=2**(i+1)
print(["no","yes"][a<=r])
