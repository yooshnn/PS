s=input().strip()
r=""
p=0
while p<len(s):
    c=0
    if s[p]=="+" or s[p]=="-":
        r+=s[p]
        p+=1
        continue
    if s[p]!="x":
        c=s[p:].split("x")[0]
        if s.find("x",p)!=-1:
            p=s.find("x",p)
            c_=str(int(c)//2)
            r+=c_ if c_!="1" else ""
            r+="xx"
            continue
        else:
            p=s.find("x",p+1)
            if p==-1:
                p=len(s)
            r+=c if c!="1" else ""
            r+="x"
            continue
    p+=1
if s=="0":
    print("W")
else:
    print(r+"+W")
