from sys import stdin

P=stdin.readline()[:-1]
N=int(stdin.readline())
plen=len(P)
sminlen=len(P)-P.count('*')

for _ in range(N):
    fail=False
    ptr=0
    s=stdin.readline()[:-1]
    if len(s) < sminlen:
        continue
    for i in range(plen):
        if P[i]=='*':
            if i==plen-1:
                continue
            if P[i+1]=='*':
                continue
            ptr=s.find(P[i+1:].split("*")[0],ptr)
            #print(ptr)
            if ptr==-1:
                fail=True
                break
            else:
                continue
        if P[i]!=s[ptr]:
            fail=True
            break
        ptr+=1
    if P[plen-1]!='*':
        if P[i]!=s[-1]:
            fail=True
    if not fail:
        print(s)
