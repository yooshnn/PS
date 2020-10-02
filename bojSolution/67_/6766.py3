from sys import stdin
def input(): return stdin.readline().rstrip()

k = int(input())
s = input()
for i, c in enumerate(s):
    print(chr((26000+ord(c)-ord("A")-3*(i+1)-k)%26 +ord("A")),end="")