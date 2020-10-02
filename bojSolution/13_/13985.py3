from sys import stdin
s=stdin.readline().split()
print(["NO","YES"][int(s[0])+int(s[2])==int(s[4])])
