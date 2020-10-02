from sys import stdin
s=str(stdin.readline()[:-1])
print(s[0],end="")
for i in range(len(s)):
    if s[i]=="-":
        print(s[i+1],end="")