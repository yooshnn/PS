from sys import stdin
def input(): return stdin.readline().rstrip()

n=int(input())
s=input()
t=0
r=0
for i in s:
    if '0'<=i and i<='9':
        t*=10
        t+=ord(i)-ord('0')
    else:
        r+=t
        t=0
print(r+t)