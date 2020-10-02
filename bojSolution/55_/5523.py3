from sys import stdin
N = int(stdin.readline())
res = [0, 0]
for _ in range(N):
    i,j=stdin.readline().split()
    if int(i)>int(j):
        res[0] += 1
    elif int(j)>int(i):
        res[1] += 1
print(res[0],end=" ")
print(res[1])