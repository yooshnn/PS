from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    c = [0]*26
    s = input().upper()
    for cha in s:
        if cha < 'A' or cha > 'Z': continue
        if cha <= 'M': c[ord(cha)-ord('A')] += 1
        else: c[ord('Z')-ord(cha)] -= 1
    print("Yes" if all(i == 0 for i in c) else "No" )