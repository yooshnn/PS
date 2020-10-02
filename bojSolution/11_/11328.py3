from sys import stdin
N=int(stdin.readline())
for _ in range(N):
    a,b=stdin.readline().split()
    print(["Impossible","Possible"][sorted(a)==sorted(b)])