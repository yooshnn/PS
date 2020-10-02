from sys import stdin

r = [0]*26
t = int(stdin.readline())

res = 0
for i in range(t):
    s = stdin.readline()[:-1]
    flag = 0
    r = [0]*26
    for j in range(len(s)):
        if r[ord(s[j])-97] == 0:
            r[ord(s[j])-97] = 1
        elif r[ord(s[j])-97] == 1:
            if s[j] != s[j-1]:
                flag = 1
    if flag == 0:
        res += 1

print(res)