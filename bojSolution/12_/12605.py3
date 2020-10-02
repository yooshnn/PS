from sys import stdin
input = stdin.readline

for t in range(int(input())):
    print("Case #", t + 1, ": ", sep="", end="")
    print(*input().split()[::-1])