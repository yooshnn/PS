from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s=input().split("0")
    for i in range(len(s)):
        s[i]=len(s[i])
    s=sorted(s)
    score=0
    while len(s)>0:
        score+=s.pop(-1)
        if len(s)>0:
            s.pop(-1)
    print(score)