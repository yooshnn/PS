import sys; input = sys.stdin.readline

res = 0
for TEST in range(int(input())):
    res += (input().find("CD") == -1)
print(res)
