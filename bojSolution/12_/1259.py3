from sys import stdin
while True:
    s=stdin.readline().rstrip()
    if s=='0':
        break
    v=1
    for i in range(len(s)//2):
        if s[i] != s[len(s)-i-1]:
            v=0
    print(["no","yes"][v])