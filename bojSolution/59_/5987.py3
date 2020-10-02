from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    n, c, s = input().split(); n=int(n); c=int(c);
    for i in range(c):
        s = s[n:]+s
    print(s)