from sys import stdin

d={'-':0,'\\':1,'(':2,'@':3,'?':4,'>':5,'&':6,'%':7,'/':-1}

while True:
    res=0
    s=input()
    if s=='#': break
    s=s[::-1]
    for i in range(len(s)):
        res+=d[s[i]]*8**i
    print(res)
