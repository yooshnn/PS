import sys; input = sys.stdin.readline

cowphabet = input().rstrip()

res = 1
i = -1
for c in input().rstrip():
    while 1:
        i += 1
        if i==26:
            res += 1
            i = 0
        if cowphabet[i] == c: break

print(res)