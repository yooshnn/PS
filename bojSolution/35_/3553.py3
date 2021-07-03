import sys; input = sys.stdin.readline

n, d = input().split()
if len(d)>len(str(10**int(n)))-1: print("No solution")
else: print(d+"0"*(int(n)-len(d)))