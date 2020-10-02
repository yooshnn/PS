from sys import stdin

stk=[]
r=0
for _ in range(int(stdin.readline())):
    del stk[:]
    s=stdin.readline()[:-1]
    for i in s:
        if not len(stk)==0:
            if stk[-1]==i:
                stk.pop()
            else:
                stk.append(i)
        else:
            stk.append(i)
    if len(stk)==0:
        r+=1

print(r)
