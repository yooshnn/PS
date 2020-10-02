from sys import stdin
a,b=stdin.readline().split()
a=int(a)
b=int(b)
c=int(stdin.readline())
a+=c//60
b+=c%60
a+=b//60
b=b%60
a=a%24
print(a,end=" ")
print(b)