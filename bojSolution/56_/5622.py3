from sys import stdin
t=[2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9]
s = stdin.readline()[:-1]

res = 0
for c in s:
    res += t[ord(c)-65] + 1
print(res)