from sys import stdin
def input(): return stdin.readline().rstrip()

for i in range(int(input())):
    n=int(input())
    for _ in range(1,n+1):
        print(_,end=" ")
    print()
