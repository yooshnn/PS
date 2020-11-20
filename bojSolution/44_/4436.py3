import sys
input = sys.stdin.readline

while 1:
    n = input()
    if not n: break
    n = int(n)

    k = 0
    d = [False for i in range(10)]
    cnt = 0

    while cnt<10:
        k += 1
        x = n*k
        for c in str(x):
            if not d[ord(c)-ord("0")]:
                d[ord(c)-ord("0")] = True
                cnt += 1
    print(k)