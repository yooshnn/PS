from sys import stdin
def input(): return stdin.readline().rstrip()


T=int(input())
for i in range(T):
    res=0
    r,c=map(int,input().split())
    for j in range(r):
        line=input()
        if j==r-1:
            res+=line.count("D")
        else:
            res+=int(line[-1]=="R")
    print(res)
