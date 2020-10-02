from sys import stdin
def input(): return stdin.readline().rstrip()

s=input()
r=1
for i in range(1,len(s)):
    if s[i]<=s[i-1]:
        r+=1
print(r)