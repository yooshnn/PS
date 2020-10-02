from sys import stdin
def input(): return stdin.readline()

maxwords=0
s=[]
l=[0]*100
while 1:
    line=input()
    if not line: break
    line=line.rstrip()
    s.append(list(line.split()))
    for i in range(len(s[-1])):
        if len(s[-1][i])>l[i]:
            l[i]=len(s[-1][i])
    if len(line.split())>maxwords:
        maxwords=len(line.split())
for i in range(len(s)):
    for j in range(len(s[i])):
        if j < len(s[i])-1:
            print(s[i][j].ljust(l[j]),end=" ")
        else:
            print(s[i][j],end=" ")
    print()