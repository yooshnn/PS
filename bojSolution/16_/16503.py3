import sys
input = sys.stdin.readline

def calc(li):
    if li[1]=="+":
        return int(li[0])+int(li[2])
    if li[1]=="-":
        return int(li[0])-int(li[2])
    if li[1]=="*":
        return int(li[0])*int(li[2])

    if (int(li[0])<0) != (int(li[2])<0):
        ret = abs(int(li[0]))//abs(int(li[2]))
        return -ret
    return abs(int(li[0]))//abs(int(li[2]))


s = input().split()
a = calc([s[0], s[1], s[2]])
b = calc([s[2], s[3], s[4]])
q = calc([s[0], s[1], b])
w = calc([a, s[3], s[4]])
print(min(q,w), max(q,w), sep="\n")