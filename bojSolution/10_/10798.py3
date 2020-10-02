from sys import stdin
a=stdin.readline()[:-1]+"               "
b=stdin.readline()[:-1]+"               "
c=stdin.readline()[:-1]+"               "
d=stdin.readline()[:-1]+"               "
e=stdin.readline()[:-1]+"               "
for i in range(15):
    if a[i] != " ":
        print(a[i],end="")
    if b[i] != " ":
        print(b[i],end="")
    if c[i] != " ":
        print(c[i],end="")
    if d[i] != " ":
        print(d[i],end="")
    if e[i] != " ":
        print(e[i],end="")
