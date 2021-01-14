import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    d, n, s, p = map(int, input().split())
    x = d+n*p
    s *= n
    if x==s: print("does not matter")
    elif x>s: print("do not parallelize")
    else: print("parallelize")