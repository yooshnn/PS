import sys; input = sys.stdin.readline

for TEST in range(int(input())):
	print(sorted([*map(int, input().split())])[7])