from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(3):
    s=input()
    streak=1
    r=1
    for i in range(1,8):
        if s[i]==s[i-1]:
            streak+=1
            if streak>r:
                r=streak
        else:
            streak=1
    print(r)