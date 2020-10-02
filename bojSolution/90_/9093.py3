from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=input().split()
    for i in s:
        print(i[::-1],end=" ")
    print()