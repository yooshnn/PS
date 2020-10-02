from sys import stdin
def input(): return stdin.readline().rstrip()
s=input()
flag=0
for i in range(len(s)-1):
    if s[i]==s[i+1]:
        flag=1
        break
print(["Odd.","Or not."][flag])
