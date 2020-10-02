from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s=input().split()
    for i in s:
        c=0
        for j in i:
            c+=ord(j)-ord('a')
        if chr(ord('a')+c%27)<='z':
            print(chr(ord('a')+c%27),end="")
        else:
            print(" ",end="")
    print()