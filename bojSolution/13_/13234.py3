from sys import stdin
def input(): return stdin.readline().rstrip()
s=input().split()
a=(s[0]=="true")
c=(s[2]=="true")
if s[1]=="AND":
    print(str(a and c).lower())
else:
    print(str(a or c).lower())