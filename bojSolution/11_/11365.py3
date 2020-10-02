from sys import stdin
while True:
    s=stdin.readline().rstrip()
    if s=="END":
        break
    print(s[::-1])