from sys import stdin
def input(): return stdin.readline().rstrip()

n=int(input())
print(n)
li=[x for x in range(1,n)]
print(*li,end=" ")
print(997)