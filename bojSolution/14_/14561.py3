import sys; input = sys.stdin.readline

d = "0123456789abcdef"

def conv(n, b):
    if n==0: return "0"
    return conv(n//b, b).lstrip("0") + d[n%b]

for TEST in range(int(input())):
    s = conv(*map(int, input().split()))
    good = True
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            good = False
            break
    print("01"[good])