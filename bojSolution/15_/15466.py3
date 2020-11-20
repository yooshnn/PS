import sys
input = sys.stdin.readline

d = {}
resName, res = "0", 0

for TEST in range(int(input())):
    n, m = map(int, input().split())
    a = set([*map(int, input().split())])
    b = set([*map(int, input().split())])
    print(1 if len(a&b)/len(a|b)>0.5 else 0)