from sys import stdin
input = stdin.readline

while 1:
    c, r = map(int, input().split())
    if c==r==0: break
    score = [0 for i in range(c)]
    for i in range(r):
        s = list(map(int, input().split()))
        for j in range(c):
            score[j] += s[j]
    print(max(score))