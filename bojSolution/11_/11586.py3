from sys import stdin
def input(): return stdin.readline().rstrip()

s=[]
n=int(input())
for i in range(n):
    s.append(input())
m=int(input())

if m==1:
    for i in s:
        print(i)
elif m==2:
    for i in s:
        print(i[::-1])
else:
    for i in range(len(s)):
        print(s[len(s)-i-1])