from sys import stdin
input = stdin.readline

n, k = map(int, input().split())
s = input().rstrip()

ss = [s[0:n//4], s[n//4:n//2], s[n//2:3*n//4], s[3*n//4:]]
if k%3 == 0:
    print(s)
elif k%3 == 1:
    print("".join([ss[0], ss[3], ss[1], ss[2]]))
elif k%3 == 2:
    print("".join([ss[0], ss[2], ss[3], ss[1]]))