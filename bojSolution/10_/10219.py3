import sys
input = sys.stdin.readline

for _ in range(int(input())):
    r, c = map(int, input().split())
    meat = []
    for i in range(r):
        meat.append(input().rstrip())
    meat.reverse()
    print(*meat, sep="\n")
