from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    n=int(input())
    s=sorted(list(map(int,input().split())))
    if len(s)==1:
        print("YES")
    else:
        flag=True
        for i in range(n):
            if s[i]-s[i-1]>1:
                flag=False
        if flag: print("YES")
        else: print("NO")
