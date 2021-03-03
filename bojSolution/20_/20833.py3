import sys; input = sys.stdin.readline

r = 0
for i in range(1, int(input())+1):
    r += i*i*i

print(r)