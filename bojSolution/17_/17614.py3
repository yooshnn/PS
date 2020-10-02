from sys import stdin
res=0
s=stdin.readline()[:-1]
for i in range(1,int(s)+1):
    res += str(i).count("3")+str(i).count("6")+str(i).count("9")
print(res)