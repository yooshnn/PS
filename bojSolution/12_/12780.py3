from sys import stdin
def input(): return stdin.readline().rstrip()
a=input()
b=input()
r=0
for i in range(1+len(a)-len(b)):
    if a[i:i+len(b)]==b:
        r+=1
print(r)