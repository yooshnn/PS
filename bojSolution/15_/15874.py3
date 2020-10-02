from sys import stdin
def input(): return stdin.readline().rstrip()
k,l=map(int,input().split())
s=input()
for i in s:
    if ord(i)>=ord('A') and ord(i)<=ord('Z'):
        print(chr((ord(i)-ord('A')+k)%26+ord('A')),end="")
    elif ord(i)>=ord('a') and ord(i)<=ord('z'):
        print(chr((ord(i)-ord('a')+k)%26+ord('a')),end="")
    else:
        print(i,end="")