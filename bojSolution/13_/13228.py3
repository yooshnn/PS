from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s=list(map(int,input().split()))
    print(s[2]+s[5]+abs(s[0]-s[3])+abs(s[1]-s[4]))