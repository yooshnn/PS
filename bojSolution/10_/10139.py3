from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    minw=minh=999999999999999
    maxw=maxh=-999999999999999
    n=int(input())
    flag=False
    for i in range(n):
        w1,w2,h1,h2=map(int,input().split())
        if w1<=minw and h1<=minh and w2>=maxw and h2>=maxh:
            flag=True
        elif w1<minw or h1<minh or w2>maxw or h2>maxh:
            flag=False
        minw=min(minw,w1)
        maxw=max(maxw,w2)
        minh=min(minh,h1)
        maxh=max(maxh,h2)
    print(["NIE","TAK"][flag])
