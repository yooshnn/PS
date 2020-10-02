from sys import stdin

n=int(input())
li=sorted(list(map(int,input().split())))
print(li[0]*li[n-1])
