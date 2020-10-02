from sys import stdin
n,m=map(int,stdin.readline().split())
d=[]
b=[]
for _ in range(n):
    d.append(stdin.readline()[:-1])
for _ in range(m):
    b.append(stdin.readline()[:-1])
j=sorted(set(d).intersection(set(b)))
print(len(j))
print("\n".join(j))
