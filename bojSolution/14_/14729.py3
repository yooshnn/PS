from sys import stdin
T=int(stdin.readline())
li=[]
for _ in range(T):
    li.append(float(stdin.readline()))
li=sorted(li)
for i in range(7):
    print("%.3f"%li[i])
