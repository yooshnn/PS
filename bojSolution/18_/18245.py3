from sys import stdin
def input(): return stdin.readline().rstrip()

skip = 1
while 1:
    skip += 1
    s = input()
    if s=="Was it a cat I saw?": break
    for i in range(0, len(s), skip):
        print(s[i], end="")
    print()