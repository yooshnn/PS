from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    a,b=map(int,input().split())
    s=input()
    for i in s:
        print(chr(ord('A')+(a*(ord(i)-ord('A'))+b)%26),end="")
    print()