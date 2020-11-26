import sys
input = sys.stdin.readline

input()
s = [*map(int, input().split())]
print(s.index(min(s)))