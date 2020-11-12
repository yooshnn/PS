import sys
input = sys.stdin.readline

N = int(input())
mail = input().rstrip()

for i in range(1, N+1):
    s = set()
    good = True
    for j in range(N-i+1):
        if mail[j:j+i] in s:
            good = False
        s.add(mail[j:j+i])
    if good:
        print(i)
        break