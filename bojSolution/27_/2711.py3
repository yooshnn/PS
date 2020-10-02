from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    x,y=input().split()
    for i in range(len(y)):
        if i==int(x)-1: continue
        print(y[i],end="")
    print()