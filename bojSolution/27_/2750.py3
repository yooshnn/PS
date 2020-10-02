from sys import stdin
t = int(stdin.readline())
li = []
for i in range(int(t)):
    li.append(int(stdin.readline()))
    li = sorted(li)
print('\n'.join(str(elem) for elem in li))