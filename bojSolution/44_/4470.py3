from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=str(input())
    print(_+1,". ",s,sep="")