import sys; input = sys.stdin.readline

n = int(input())
s = [*set([*map(int, input().split())])]

if len(s)==n and max(s)==n and min(s)==1:
    print("TAK")
else:
    print("NIE")
