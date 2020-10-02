from sys import stdin
def input(): return stdin.readline().rstrip()

s = input()
t = input()

sc = [s.count(chr(i+97)) for i in range(26)]
tc = [t.count(chr(i+97)) for i in range(26)]
wc = t.count("*")

good = False
for i in range(26):
    if sc[i] == tc[i]:
        pass
    elif sc[i] < tc[i]:
        break
    else:
        wc -= sc[i] - tc[i]
        if wc < 0:
            break
    if i == 25:
        good = True

print("A" if good else "N")