import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip()
    if len(s)==7 and s[0]==s[1] and s[0]==s[4] and s[2]==s[3] and s[2]==s[5] and s[2]==s[6] and s[0]!=s[2]:
        print(1)
    else:
        print(0)