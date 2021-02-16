import sys; input = sys.stdin.readline

res = 0
for _ in range(int(input())):
    line = input().rstrip()
    if "pink" in line.lower() or "rose" in line.lower():
        res += 1
print(res if res>0 else "I must watch Star Wars with my daughter")