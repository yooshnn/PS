import sys
input = sys.stdin.readline

input()
c = set(input().split())
input()
for i in input().split():
    print(1 if i in c else 0, end=" ")