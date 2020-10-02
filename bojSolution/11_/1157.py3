s = input().upper()
li = [0]*26
for c in s:
    li[ord(c)-65] += 1
large = 0
cha = '?'
for i in range(26):
    if li[i] > large:
        large = li[i]
        cha = chr(i+65)
    elif li[i] == large:
        cha = '?'
print(cha)