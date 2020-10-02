from sys import stdin

a=list(stdin.readline().split())
b=list(stdin.readline().split())

p=int(a[4])+60*int(a[2])+3600*int(a[0])
q=int(b[4])+60*int(b[2])+3600*int(b[0])
if q-p<0:
    q+=3600*24
print(q-p)
