while True:
    s=list(input().split()[0])
    if s[0]=="#":
        break
    if "a" not in s and "i" not in s and "u" not in s and "e" not in s and "o" not in s:
        print("".join(s),"ay",sep="")
    elif s[0]=="a" or s[0]=="i" or s[0]=="u" or s[0]=="e" or s[0]=="o":
        print("".join(s),"ay",sep="")
    else:
        while s[0]!="a" and s[0]!="i" and s[0]!="u" and s[0]!="e" and s[0]!="o":
            s.append(s[0])
            s=s[1:]
        print("".join(s),"ay",sep="")