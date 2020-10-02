from sys import stdin
def input(): return stdin.readline().rstrip()

T = input()
S = input()
isGood = False

for i in range(len(S) - 1):
    if S in T:
        isGood = True
        break
    S = S[-1] + S[:-1]

print("yes" if isGood else "no")