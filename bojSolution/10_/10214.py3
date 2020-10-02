from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    y,k=0,0
    for i in range(9):
        yy,kk=map(int,input().split())
        y+=yy
        k+=kk
    if y>k:
        print("Yonsei")
    elif y<k:
        print("Korea")
    else:
        print("Draw")