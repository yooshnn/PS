from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    p = input()
    if p == "end": break
    good = any(x in "aeiou" for x in p)
    for i in range(len(p)):
        if not good: break
        if i<len(p)-2:
            if all(x in "aeiou" for x in p[i:i+3]) or all(x not in "aeiou" for x in p[i:i+3]): good = False
        if i<len(p)-1:
            if p[i]==p[i+1] and p[i] not in "eo": good = False
    print("<",p,"> is"," " if good else " not ", "acceptable.", sep="")