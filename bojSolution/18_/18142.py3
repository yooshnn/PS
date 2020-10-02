from sys import stdin
def input(): return stdin.readline().rstrip()
l=["tapioka","bubble","pearls"]
s=input().split()
c=0
for i in s:
    if i in l:
        c+=1
        pass
    else:
        print(i,end=" ")
if c==len(s):
    print("nothing")