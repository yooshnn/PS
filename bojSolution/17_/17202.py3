from sys import stdin
def input(): return stdin.readline().rstrip()

a = input()
b = input()
s = ""
for i in range(8):
    s += a[i] + b[i]

while 1:
    t = ""
    for i in range(len(s)-1):
        t += str((int(s[i])+int(s[i+1]))%10)
    if int(t) < 100 and len(t) <= 2:
        break
    else:
        s = t

print(t)