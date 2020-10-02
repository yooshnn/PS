from sys import stdin
def input(): return stdin.readline().rstrip()
li=sorted(map(int,input().split()))
s=input()
for i in s:
    print(li[ord(i)-ord('A')],end=" ")