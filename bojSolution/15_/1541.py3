from sys import stdin
s = stdin.readline()
tempno = 0
res = 0
base = True
flag = False
prev = '+'
for i in range(len(s)):
    if base and s[i] in ['+','-']:
        base = False
        res = tempno
        tempno = 0
        prev = s[i]
    elif s[i] in ['+','-','\n']:
        if prev == '-':
            flag = True
        if flag:
            res -= tempno
            tempno = 0
        else:
            res += tempno
            tempno = 0
        prev = s[i]
        base = False
    else:
        tempno *= 10
        tempno += int(s[i])
print(res)