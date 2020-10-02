from sys import stdin
def input(): return stdin.readline().rstrip()
n=input()
s=sorted(set(map(int,input().split())))
print(*s)
