n=input()
a=n[:len(n)//2]
b=n[len(n)//2:]
aa=0
bb=0
for i in a:
    aa+=int(i)
for i in b:
    bb+=int(i)
print(["READY","LUCKY"][aa==bb])