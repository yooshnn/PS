import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = [*map(int, input().split())]

if n-m != 1:
    print("No")
    sys.exit(0)

v = [0 for i in range(n+1)]
v[0] = 1

flag = 0
for i, c in enumerate(s):
    if c != i+1+flag:
        if flag==0:
            flag = 1
        else:
            flag = -1
            break
    if c>n or v[c]==1:
        print("No")
        sys.exit(0)
    v[c] = 1

print("Yes\n%d"%v.index(0) if flag>=0 else "No")