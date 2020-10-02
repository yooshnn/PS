from sys import stdin
r=0
while 1:
    line=stdin.readline()
    if not line: break
    r+=line.count("joke")
print(r)