import sys
input = sys.stdin.readline

while 1:
    n, a, w = input().split(); a, w = int(a), int(w)
    if n == "#": break
    print(n,"Senior" if a>17 or w>79 else "Junior")
