from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    r=0
    n=int(input())
    candy=list(map(int,input().split()))
    orange=list(map(int,input().split()))
    candymin=min(candy)
    orangemin=(min(orange))
    for i in range(n):
        candy[i]-=candymin
        orange[i]-=orangemin
        r+=max(candy[i],orange[i])
    print(r)
