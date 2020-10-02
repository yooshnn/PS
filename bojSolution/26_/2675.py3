from sys import stdin

t = stdin.readline()
for i in range(int(t)):
    r,s=stdin.readline().split()
    u=""
    for v in s:
        u+=v*int(r)
    print(u)