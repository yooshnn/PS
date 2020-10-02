a,b=input().split()
a=a[::-1]
b=b[::-1]
a=int(a)
b=int(b)
print(a if a>b else b)