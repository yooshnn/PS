from sys import stdin

a,b,c=stdin.readline().split()
a = int(a)
b = int(b)
c = int(c)

if b>=c:
    print(-1)
else:
    print(a//(c-b)+1)