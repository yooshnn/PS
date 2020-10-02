from sys import stdin
input = stdin.readline

good = True
content = input().rstrip()
space = int(input())
key = list(map(int, input().split()))
title = ""

for c in content.split():
    title += c[0].upper()

content += title


if key[ord(content[0].upper()) - 65] >= 1:
    key[ord(content[0].upper()) - 65] -= 1
else:
    good = False

for i, c in enumerate(content):
    if not good: break
    if i == 0: continue
    if c == " ":
        if content[i-1] == " ":
            continue
        if space >= 1:
            space -= 1
        else:
            good = False
        continue
    if content[i-1]==content[i]: continue
    if key[ord(c.upper()) - 65] >= 1:
        key[ord(c.upper()) - 65] -= 1
    else:
        good = False

if good:
    print(title)
else:
    print(-1)
