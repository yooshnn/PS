import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    d = {}
    n = int(input())
    for c in input().split():
        try: d[c] += 1
        except: d[c] = 1
    for c in input().split():
        try: d[c] -= 1
        except: d[c] = -1
    print("CHEATER" if any(d[i]!=0 for i in d.keys()) else "NOT CHEATER")