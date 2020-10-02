from sys import stdin
N,Q=stdin.readline().split()
a=[int(x) for x in stdin.readline().split()]
b=[]
for i in range(1,len(a)):
    b.append(abs(a[i]-a[i-1]))
for _ in range(int(Q)):
    f,t=map(int,stdin.readline().split())
    print(sum(b[f-1:t-1]))
