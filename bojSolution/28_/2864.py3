from sys import stdin
x,y=stdin.readline().split()
x2=x.replace("5","6")
y2=y.replace("5","6")
x3=x.replace("6","5")
y3=y.replace("6","5")
print(int(x3)+int(y3),int(x2)+int(y2))
