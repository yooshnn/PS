from sys import stdin
s=stdin.readline()[:-1]
skip = 0
res = 0
for i in range(len(s)):
    if skip == 0:
        res += 1
    else:
        skip -= 1

    if s[i:i+2] == "c=":
        skip = 1
    if s[i:i+2] == "c-":
        skip = 1
    if s[i:i+3] == "dz=":
        skip = 2
    if s[i:i+2] == "d-":
        skip = 1
    if s[i:i+2] == "lj":
        skip = 1
    if s[i:i+2] == "nj":
        skip = 1
    if s[i:i+2] == "s=":
        skip = 1
    if s[i:i+2] == "z=":
        skip = 1

print(res)