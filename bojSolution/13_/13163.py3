from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    s=stdin.readline().split()
    print("god",end="")
    print("".join(s[1:]))