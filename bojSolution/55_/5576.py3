import sys; input = sys.stdin.readline

a = [int(input()) for i in range(10)]
b = [int(input()) for i in range(10)]
print(sum(sorted(a)[-3:]), sum(sorted(b)[-3:]))
