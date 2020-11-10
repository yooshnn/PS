import sys
input = sys.stdin.readline
res = 0

for _ in range(int(input())):
    p = input().rstrip()
    q = p[::-1]
    r = str(int(p)+int(q))

    good = True
    for i in range(len(r)//2):
        if r[i]!=r[-1-i]:
            good = False
    print("YES" if good else "NO")