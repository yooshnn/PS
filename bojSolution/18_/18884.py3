from sys import stdin
n,m=map(int,stdin.readline().split())
s=stdin.readline().split()
t=stdin.readline().split()
q=int(stdin.readline())
for _ in range(q):
    i=int(stdin.readline())-1
    print(s[i%n]+t[i%m])