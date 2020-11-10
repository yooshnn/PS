import sys
input = sys.stdin.readline

for _ in range(int(input())):
    input()
    s = set(input().split())
    input()
    for c in input().split():
        print(1 if c in s else 0)