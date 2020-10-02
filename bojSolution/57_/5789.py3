from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    s = input()
    if s[len(s)//2-1] == s[len(s)//2]: print("Do-it")
    else: print("Do-it-Not")