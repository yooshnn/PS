from sys import stdin
li=[]
li.append(350.34)
li.append(230.90)
li.append(190.55)
li.append(125.30)
li.append(180.90)
T=int(stdin.readline())
for _ in range(T):
    r=0
    a=list(map(int,stdin.readline().split()))
    for i in range(5):
        r+=li[i]*a[i]
    print("$","%.2f"%r,sep="")
