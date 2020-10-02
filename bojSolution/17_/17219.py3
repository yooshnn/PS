from sys import stdin, stdout
d={}
N,M=map(int,stdin.readline().split())
for _ in range(N):
    S,T=stdin.readline().split()
    d[S]=T
for _ in range(M):
    S=stdin.readline()[:-1]
    stdout.write(d[S])
    stdout.write("\n")