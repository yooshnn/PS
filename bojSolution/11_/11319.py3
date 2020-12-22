import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip().lower()
    res = 0
    for c in s:
        if c in "aiueo": res += 1
    print(len(s)-s.count(" ")-res, res)
