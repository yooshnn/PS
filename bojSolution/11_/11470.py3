import sys
input = sys.stdin.readline

s = input().rstrip()
r = ""
z=0
for i, c in enumerate(s):
    if i==0: r+=c
    else:
        if s[i] in "+-": z=0
        r+=c
        if s[i-1]=="-": z=1
        if i!=len(s)-1 and z and not (i==len(s)-1 or s[i+1]in"+-"): r+="+"
        if i==len(s)-1 or s[i+1] not in "+-0": z=max(0,z-1)
print(r)
