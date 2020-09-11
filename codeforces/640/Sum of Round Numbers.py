from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    x = input()
    res = 0
    r = ""
    for i in range(len(x)):
        if x[i] == '0': continue
        res += 1
        r += x[i] + "0"*(len(x)-i-1) + " "
    print(res)
    print(r)
