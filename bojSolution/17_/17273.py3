from sys import stdin

n,m=stdin.readline().split()
n = 1
f = True

front,back=stdin.readline().split()
front = int(front)
back = int(back)

for i in range(int(m)):
    k = int(stdin.readline())
    if f:
        if front <= k:
            f = not f
    else:
        if back <= k:
            f = not f

if f:
    print(front)
else:
    print(back)