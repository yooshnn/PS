from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    loc, s = input().split()
    cnt = [0]*4
    for c in s:
        if c=='B': cnt[0] += 2
        if c=='C': cnt[1] += 1
        if c=='M': cnt[2] += 4
        if c=='W': cnt[3] += 3
    if sorted(cnt)[2]==max(cnt):
        print("%s: There is no dominant species" % loc)
    else:
        print("%s: The %s is the dominant species" % (loc, ["Bobcat","Coyote","Mountain Lion","Wolf"][cnt.index(max(cnt))]))