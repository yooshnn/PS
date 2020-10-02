s=input()
if len(s)==4:
    a=10
    b=10
elif len(s)==3:
    if s[1]=="0":
        a=10
        b=s[2]
    else:
        b=10
        a=s[0]
else:
    a=s[0]
    b=s[1]
a=int(a)
b=int(b)
print(a+b)
