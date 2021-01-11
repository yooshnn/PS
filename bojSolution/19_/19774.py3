import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip()
    if (int(s[:2])**2 + int(s[2:])**2)%7 == 1: print("YES")
    else: print("NO")