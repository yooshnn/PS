from functools import cmp_to_key
from sys import stdin

def sortbydict(a,b):
    if a<b:
        return -1
    elif a>b:
        return 1
    else:
        return 0

def sortbylen(a,b):
    if len(a)<len(b):
        return -1
    elif len(a)>len(b):
        return 1
    else:
        return 0

N=int(stdin.readline())
li=[]
for _ in range(N):
    li.append(str(stdin.readline()[:-1]))
li=list(set(li))
li=sorted(li,key=cmp_to_key(sortbydict))
li=sorted(li,key=cmp_to_key(sortbylen))

for i in range(len(li)):
    print(li[i])