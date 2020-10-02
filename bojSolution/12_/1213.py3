from sys import stdin
def input(): return stdin.readline().rstrip()

s = input()
alphabet = [0]*26
for c in s:
    alphabet[ord(c) - ord("A")] += 1

oddCnt = 0
for a in alphabet:
    if a%2 == 1: oddCnt += 1

if oddCnt > 1:
    print("I'm Sorry Hansoo")
else:
    r = ""
    for i, a in enumerate(alphabet):
        for _ in range(a//2): r+=chr(i+65)
    if oddCnt == 1:
        for i, a in enumerate(alphabet):
            if a%2 == 1: r+=chr(i+65)
    for i in range(25, -1, -1):
        for _ in range(alphabet[i]//2): r+=chr(i+65)
    print(r)