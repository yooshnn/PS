import sys
input = sys.stdin.readline

for i in range(int(input())):
    s = input().rstrip()
    res = True
    for i in range(len(s)//2):
        if s[i] != s[len(s)-1-i]:
            res = False
    print("1" if res else "2")