from sys import stdin
def input(): return stdin.readline().rstrip()

roman = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

s = input()
r = 0

for i in range(len(s)//2):
    t = int(s[i*2]) * roman[s[i*2+1]]
    if i != len(s)//2-1:
        t *= -1 if roman[s[i*2+1]] < roman[s[i*2+3]] else 1
    r += t

print(r)