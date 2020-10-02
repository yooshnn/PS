a=[int(input())]
a.append(int(input()))
a.append(int(input()))
a=sorted(a)
if sum(a) != 180:
    print("Error")
elif a[0]==a[1] and a[2]==60:
    print("Equilateral")
elif a[0]==a[1] or a[1]==a[2]:
    print("Isosceles")
else:
    print("Scalene")