from sys import stdin
def input(): return stdin.readline()
n=int(input())
li=list(map(int,input().split()))
print((n*(n+1)//2)-sum(li))