from sys import stdin
def input(): return stdin.readline().rstrip()

vowel = "aiueo"
s = input()
r = ""

for c in s:
    r += c

    if c in vowel: continue

    dl, dr = 99, 99
    for i in range(1, 26):
        if dl == 99:
            if chr(ord(c) - i) in vowel:
                dl = i
        if dr == 99:
            if chr(ord(c) + i) in vowel:
                dr = i

    if dr == 99:
        r += chr(ord(c) - dl)
    else:
        if dl <= dr:
            r += chr(ord(c) - dl)
        else:
            r += chr(ord(c) + dr)

    if c == "z":
        r += "z"
    else:
        c = chr(ord(c) + 1)
        while c in vowel:
            c = chr(ord(c) + 1)
        r += c

print(r)