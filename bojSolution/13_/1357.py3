from sys import stdin
s=stdin.readline().split()
print(int(str(int(s[0][::-1])+int(s[1][::-1]))[::-1]))