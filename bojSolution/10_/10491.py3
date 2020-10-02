from sys import stdin
while 1:
    s=stdin.readline()
    if not s:break
    print(["no","yes"]["PROBLEM"in s.upper()])