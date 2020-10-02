from sys import stdin
s=stdin.readline()
c=0
for i in s:
    if c==0:
        if i=="U":
            c+=1
    elif c==1:
        if i=="C":
            c+=1
    elif c==2:
        if i=="P":
            c+=1
    elif c==3:
        if i=="C":
            c+=1
if c==4:
    print("I love UCPC")
else:
    print("I hate UCPC")