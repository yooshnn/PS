for _ in range(int(input())):
    s=input().split()
    r=0
    for i in s:
        if i=='u':
            r+=1
        if i=='ur':
            r+=1
    for i in range(len(s)-1):
        if (s[i]=="should" or s[i]=="would")and(s[i+1]=="of"):
            r+=1
    for i in s:
        if "lol" in i:
            r+=1
    print(r*10)