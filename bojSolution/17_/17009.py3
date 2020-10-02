a=[]
b=[]
a.append(int(input())*3)
a.append(int(input())*2)
a.append(int(input()))
b.append(int(input())*3)
b.append(int(input())*2)
b.append(int(input()))
if sum(a)>sum(b):
    print("A")
elif sum(b)>sum(a):
    print("B")
else:
    print("T")
