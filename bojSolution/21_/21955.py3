import sys; input = sys.stdin.readline

s = input().rstrip()
print(s[:len(s)//2] + " " + s[len(s)//2:])