import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    print(sum([*map(int, input().split())]))