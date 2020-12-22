import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = [*map(int, input().split())]
    if len(s)<=3:
        print("YES"); continue
    good = True
    for i in range(3, len(s)):
        if s[i]!=s[i-2]+s[i-1]: good = False
    print("YES" if good else "NO")