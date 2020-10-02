from sys import stdin
def input(): return stdin.readline().rstrip()

s = input()
r = True
for i in range(len(s)//2):
    if s[i] != s[len(s)-1-i]:
        r = False
print("true" if r else "false")