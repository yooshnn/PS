from sys import stdin
def input(): return stdin.readline().rstrip()
li=[]
for _ in range(int(input())):
    del li[:]
    for i in range(int(input())):
        x,y=input().split()
        li.append(list([int(x),y]))
    print(sorted(li)[len(li)-1][1])