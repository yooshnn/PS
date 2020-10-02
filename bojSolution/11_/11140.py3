from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s=input()
    if "lol" in s:
        print(0)
        continue
    if "l" in s:
        f=False
        for i in range(len(s)-2):
            if s[i]=="l" and s[i+2]=="l":
                f=True
                break
        if f:
            print(1)
            continue
    if "ll" in s:
        print(1)
    elif "lo" in s:
        print(1)
    elif "ol" in s:
        print(1)
    elif "l" in s:
        print(2)
    elif "o" in s:
        print(2)
    else:
        print(3)