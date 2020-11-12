import sys
input = sys.stdin.readline
t = input().rstrip()
r = 0
for _ in range(int(input())):
    s = input().rstrip()
    s = s + s
    r += (s.find(t) > -1)
print(r)