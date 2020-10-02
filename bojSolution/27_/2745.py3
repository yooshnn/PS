from sys import stdin
def input(): return stdin.readline().rstrip()

N,B=input().split()
B=int(B)
N=str(N)[::-1]

j=1
res=0
for i in N:
    if ord(i)<=ord('9'):
        r=(ord(i)-ord('0'))*j
    else:
        r=(ord(i)-ord('A')+10)*j
    j*=B
    res+=r
print(res)