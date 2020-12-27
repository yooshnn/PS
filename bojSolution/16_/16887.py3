import sys; input = sys.stdin.readline

N = int(input())
s = [*map(int, input().split())]
r = 0
for i in s:
    if i <= 3: r ^= 0
    elif i <= 15: r ^= 1
    elif i <= 81: r ^= 2
    elif i <= 6723: r ^= 0
    elif i <= 50625: r ^= 3
    elif i <= 2562991875: r ^= 1
    else: r ^= 2

print("cubelover" if r==0 else "koosaga")
