from sys import stdin
def input(): return stdin.readline().rstrip()
li=[]
for i in range(int(input())):
    x,y=input().split()
    li.append([int(x),y])
li=sorted(li,key=lambda x:x[0])
for elem in li:
    print(elem[0],elem[1])