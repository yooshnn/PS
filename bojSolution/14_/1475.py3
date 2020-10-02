from sys import stdin
s=[]
l=stdin.readline()[:-1]
res=0
for i in l:
    if i in s:
        s.remove(i)
    elif i=="6" and ("9" in s):
        s.remove("9")
    elif i=="9" and ("6" in s):
        s.remove("6")
    else:
        for j in range(10):
            s.append(str(j))
        s.remove(i)
        res+=1
print(res)