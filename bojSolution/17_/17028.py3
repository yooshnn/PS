import sys
input = sys.stdin.readline

n = int(input())
cow = [*map(int, input().split())]

cur = n-1
r = 1
while 1:
    if cow[cur] > cow[cur-1]:
        r+=1
        cur -= 1
        if cur == 0: break
    else:
        break

print(n-r)