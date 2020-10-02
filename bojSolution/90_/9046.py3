for _ in range(int(input())):
    li=[0]*26
    res=[]
    s=input()
    for i in s:
        if i==' ':continue
        li[ord(i)-ord('a')]+=1
    for i in range(26):
        if li[i]==max(li):
            res.append(chr(i+ord('a')))
    if len(res)==1:
        print(res[0])
    else:
        print("?")