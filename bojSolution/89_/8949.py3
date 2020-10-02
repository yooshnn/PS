a,b=map(int,input().split())
a = "%07d" % a
b = "%07d" % b
#print(a,b)
r=""
for i in range(7):
    r+=str(int(a[i])+int(b[i]))
print(int(r))