import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().split()
    R, r = 0, 0
    for c in s:
        if c=='X': r += 1
        else: r = 0
        R = max(R, r)
    print("The longest contiguous subsequence of X's is of length", R)
