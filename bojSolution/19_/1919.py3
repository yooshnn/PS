from sys import stdin
def input(): return stdin.readline().rstrip()
p=[0]*26
q=[0]*26
a=input()
b=input()
for i in a:
    p[ord(i)-ord('a')]+=1
for i in b:
    q[ord(i)-ord('a')]+=1
for i in range(26):
    p[i]=abs(p[i]-q[i])
print(sum(p))