from sys import stdin
T=int(stdin.readline())
d={}
l=[]
for i in range(T):
    s=stdin.readline()[0]
    try:
        d[s]+=1
    except:
        d[s]=1
for k in d:
    if d[k]>=5:
        l.append(k)
l=sorted(l)
if l == []:
    print("PREDAJA")
else:
    for i in l:
        print(i,end="")