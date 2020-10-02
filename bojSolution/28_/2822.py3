from sys import stdin
li=[]
for _ in range(1,9):
    li.append([int(stdin.readline()),_])
li=sorted(li)[3:]
res=0
for i in li:
    res+=i[0]
    del i[0]
print(res)
li=sorted(li)
for i in li:
    print(i[0],end=" ")
