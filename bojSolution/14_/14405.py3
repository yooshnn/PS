s=input()
while len(s)>0:
    if len(s)==1:
        f=True
        break
    elif len(s)>=2:
        if s[:2]=="pi" or s[:2]=="ka":
            s=s[2:]
            continue
        if len(s)>=3:
            if s[:3]=="chu":
                s=s[3:]
                continue
    break
print(["YES","NO"][len(s)>0])