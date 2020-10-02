from sys import stdin

while True:
    n=stdin.readline().strip()
    if n=='0':
        break
    res=1
    for i in n:
        if i=='1':
            res+=3
        elif i=='0':
            res+=5
        else:
            res+=4
    print(res)