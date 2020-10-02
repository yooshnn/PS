from sys import stdin
def input(): return stdin.readline().rstrip()
a=input()
b=input()
r=0
for i in range(1+len(a)-len(b)):
    flag=True
    for j in range(len(b)):
        if a[i+j]==b[j]: flag=False
    if flag:
        r+=1
print(r)