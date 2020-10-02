from sys import stdin
s=stdin.readline().rstrip()
v=1
for i in range(len(s)//2):
    if s[i] != s[len(s)-i-1]:
        v=0
print(["0","1"][v])