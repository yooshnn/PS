from sys import stdin
s=""
for line in stdin:
    s+=line+" "
s=s.split()[:-1]
l=[]
for elem in s:
    L=0
    for i in range(len(elem)):
        if (ord(elem[i])>=ord('a') and ord(elem[i])<=ord('z')) or (ord(elem[i])>=ord('A') and ord(elem[i])<=ord('Z')) or elem[i]=='-':
            L+=1
    l.append(L)
for i in range(len(l)):
    if l[i]==max(l):
        for ii in range(len(s[i])):
            if (ord(s[i][ii])>=ord('a') and ord(s[i][ii])<=ord('z')) or (ord(s[i][ii])>=ord('A') and ord(s[i][ii])<=ord('Z')) or s[i][ii]=='-':
                print(s[i][ii].lower(),end="")
        break