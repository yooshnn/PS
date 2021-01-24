import sys; input = sys.stdin.readline

bad, res = set(input().split()[1:]), 0
for _ in range(int(input())):
    t = set(input().split()[1:])
    if len(t&bad)==0: res += 1
print(res)