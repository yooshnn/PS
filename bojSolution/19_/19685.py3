import sys
input = sys.stdin.readline

s, e = map(int, input().split())
for i in range(s, e+1):
    s = str(i)
    res = True
    for j in range(len(s)//2):
        if s[j] != s[len(s)-1-j]:
            res = False
            break
    print("Palindrome!" if res else i)