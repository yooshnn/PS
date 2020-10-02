from sys import stdin
res=1
for _ in range(int(input())):
    res+=int(stdin.readline())-1
print(res)