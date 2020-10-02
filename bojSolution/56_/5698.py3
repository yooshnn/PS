while 1:
    s=input().rstrip()
    if s=='*': break
    s=s.upper().split()
    a=s[0][0]
    flag=True
    for i in s:
        if i[0]!=a:
            flag=False
    print(["N","Y"][flag])