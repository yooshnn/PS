import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    if n>6: print(1)
    else: print("x000210"[n])
