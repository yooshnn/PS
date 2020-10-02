from sys import stdin
def input(): return stdin.readline().rstrip()

s = input()
isGood = True

for i in s:
    if i not in ['I','O','S','H','Z','X','N']:
        isGood = False

print("YES" if isGood else "NO")