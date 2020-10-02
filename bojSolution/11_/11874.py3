from sys import stdin
def input(): return stdin.readline().rstrip()

L=int(input());D=int(input());X=int(input())
f1=False
q=0
for i in range(L,D+1):
    s=str(i)
    r=0
    for j in s:
        r+=ord(j)-ord('0')
    if r==X:
        q=i
        if not f1:
            print(i)
            f1=True
print(q)