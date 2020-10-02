from sys import stdin
stdin.readline()
a = list(map(int,stdin.readline().split()))
maximum = max(a)
s = 0
for i in range(len(a)):
    s += a[i] * 100/maximum
print(s/len(a))