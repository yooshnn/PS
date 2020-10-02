for _ in range(int(input())):
    s="{0:b}".format(int(input()))[::-1]
    for i in range(len(s)):
        if s[i]=="1":
            print(i,end=" ")
    print()