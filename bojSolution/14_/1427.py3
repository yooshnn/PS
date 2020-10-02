from sys import stdin
s = sorted(stdin.readline()[:-1])[::-1]
print("".join(s))