from sys import stdin
t = stdin.readline()
li = []
for i in range(int(t)):
    li.append(int(stdin.readline()))
li = sorted(li)
for elem in li:
    print(elem)