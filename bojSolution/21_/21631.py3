import sys; input = sys.stdin.readline

w, b = map(int, input().split())
if w+1 >= b: print(b)
else: print(min(w+1, b))
