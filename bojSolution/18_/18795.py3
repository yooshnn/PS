import sys
input = sys.stdin.readline

res = 0
input()
res += sum(map(int, input().split()))
res += sum(map(int, input().split()))
print(res)
