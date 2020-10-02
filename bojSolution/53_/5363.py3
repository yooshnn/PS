from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s = input().split()
    print(*s[2:], *s[:2])