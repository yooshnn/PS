from sys import stdin
def input(): return stdin.readline().rstrip()

err=False
t=0
s=input()
r=""

for i in range(len(s)):
    if err:
        break
    if i==0:
        if s[i]>='a' and s[i]<='z':
            r+=s[i]
        else:
            err=True
        continue
    if t==0:
        if s[i]=='_':
            t=2
            if i==len(s)-1:
                err=True
                continue
            if s[i+1]=='_':
                err=True
                continue
            r+=chr(ord(s[i+1])-ord('a')+ord('A'))
        if s[i]>='A' and s[i]<='Z':
            t=1
            r+='_'+chr(ord(s[i])-ord('A')+ord('a'))
        elif s[i]>='a' and s[i]<='z':
            r+=s[i]
    elif t==1:
        if s[i]=='_':
            err=True
            continue
        if s[i]>='A' and s[i]<='Z':
            r+='_'+chr(ord(s[i])-ord('A')+ord('a'))
        else:
            r+=s[i]
    elif t==2:
        if s[i]>='A' and s[i]<='Z':
            err=True
            continue
        if s[i]=='_':
            if i==len(s)-1:
                err=True
                continue
            if s[i+1]=='_':
                err=True
                continue
            r+=chr(ord(s[i+1])-ord('a')+ord('A'))
        if s[i-1]=='_':
            continue
        elif s[i]>='a' and s[i]<='z':
            r+=s[i]
print("Error!" if err else r)