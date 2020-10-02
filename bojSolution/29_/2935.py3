from sys import stdin
a=int(stdin.readline())
o=stdin.readline()[:-1]
b=int(stdin.readline())
if o=="*":
    print(a*b)
else:
    print(a+b)