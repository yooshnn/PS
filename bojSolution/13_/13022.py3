from sys import stdin
def input(): return stdin.readline().rstrip()

#flowffllooww

res = True
wDis = 0
base = 0
s = input()
sLen = len(s)
if s[0] != "w": res = False
if s[-1] != "f": res = False
s += "z"*51



for i in range(sLen):
    if not res: break
    if s[i] == "w":
        if wDis == 0: base = i
        wDis += 1
    else:
        if wDis > 0:
            for j in range(wDis):
                if s[base+wDis+j] != "o" or s[base+wDis*2+j] != "l" or s[base+wDis*3+j] != "f":
                    res=False
                    break
            if s[base+wDis*4] not in ["w", "z"]:
                res = False
        wDis = 0


print(1 if res else 0)