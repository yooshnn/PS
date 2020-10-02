from sys import stdin
def input(): return stdin.readline()
li=[0]*26
il=[0]*26
s=""
while 1:
    a=input()
    if not a: break
    a=a.rstrip()
    b=input().rstrip()

    for i in a:
        li[ord(i)-ord('a')]+=1
    for i in b:
        il[ord(i)-ord('a')]+=1
    for i in range(26):
        if li[i]>0 and il[i]>0:
            s+=chr(i+ord('a'))*min(li[i],il[i])
    print(*sorted(s),sep="")
    li=[0]*26
    il=[0]*26
    s=""