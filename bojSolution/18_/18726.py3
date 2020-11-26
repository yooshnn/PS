import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip()
    res = []
    while len(s) >= 3:
        t = [s[:(len(s)+1)//2], s[(len(s)+1)//2:]]
        t[0] = str(int(t[0])-1)
        t[0] += t[0][:len(t[1])][::-1]
        res.append(t[0])
        s = str(int(s)-int(t[0]))
    while len(s) == 2:
        if int(s[0]+s[0])<=int(s):
            res.append(s[0]+s[0])
            s = str(int(s)-int(s[0]+s[0]))
        else:
            res.append("9")
            s = str(int(s)-9)
    if len(s) == 1 and int(s)!=0:
        res.append(s)
    print(len(res))
    print("\n".join(res))