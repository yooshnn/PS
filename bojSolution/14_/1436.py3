from sys import stdin
n = int(stdin.readline())

li = []
temp = 666
while(len(li)<n):
    if str(temp).count("666") > 0:
        li.append(temp)
    temp += 1

print(li[-1])