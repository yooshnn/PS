from sys import stdin
n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]
b,c = [int(x) for x in stdin.readline().split()]
ans = len(a)

for index in range(len(a)):
    a[index] -= b
    if a[index] > 0:
        ans += a[index]//c
        if a[index]//c != a[index]/c:
            ans += 1

print(ans)