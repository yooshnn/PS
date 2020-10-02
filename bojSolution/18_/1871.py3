from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=input().split('-')
    a=(ord(s[0][2])-ord('A'))*(26**0)+(ord(s[0][1])-ord('A'))*(26**1)+(ord(s[0][0])-ord('A'))*(26**2)
    b=int(s[1])
    print(["not nice","nice"][abs(a-b)<=100])