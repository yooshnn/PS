from sys import stdin
def input(): return stdin.readline().rstrip()

m, M = 0, 0
for _ in range(int(input())):
    s = input()
    sLen = len(s)
    M = max(M, int("9" * sLen))
    m = max(m, int(s), int("1" + "0" * (sLen-1)))
print(m,M,sep="\n")