from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=str(input())
    print(s[0].upper(),end="")
    print(s[1:])