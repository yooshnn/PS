a, b = input(), input()

r = [[], [], [], [], []]

for i in range(len(a)):
    r[0].append(str(int(a[i])&int(b[i])))
    r[1].append(str(int(a[i])|int(b[i])))
    r[2].append(str(int(a[i])^int(b[i])))
    r[3].append("1" if a[i]=="0" else "0")
    r[4].append("1" if b[i]=="0" else "0")

for i in range(5): print("".join(r[i]))