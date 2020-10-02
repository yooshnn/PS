a=[]
b=[]
a.append(int(input()))
a.append(int(input()))
a.append(int(input()))
a.append(int(input()))

b.append(int(input()))
b.append(int(input()))

a=sorted(a)
b=sorted(b)

print(sum(a[1:])+sum(b[1:]))