import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().split()
    t = 0
    N, T, L = map(int, s[1:])
    L *= 10**8
    if s[0]=="O(N)":
        t = N*T
    elif s[0]=="O(2^N)":
        tt = 1
        while 1:
            t = 2**tt
            if T*t>L or tt==N:
                t = T*t
                break
            tt += 1
    elif s[0]=="O(N^2)":
        t = N*N*T
    elif s[0]=="O(N^3)":
        t = N*N*N*T
    else:
        f, cnt = 1, 1
        while 1:
            f *= cnt
            if T*f>L or cnt==N:
                t = T*f
                break
            cnt += 1
    print("May Pass." if t<=L else "TLE!")
