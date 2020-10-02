s=input()
res=1
for i in range(len(s)):
    if i==0:
        if s[i]=="d":
            res*=10
        elif s[i]=="c":
            res*=26
    else:
        if s[i]=="d":
            if s[i-1]=="d":
                res*=9
            else:
                res*=10
        elif s[i]=="c":
            if s[i-1]=="c":
                res*=25
            else:
                res*=26
print(res)