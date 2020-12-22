import sys; input = sys.stdin.readline

d = "0123456789abcdefghijklmnopqrstuvwxyz"
def conv(num, base):
    q, r = divmod(num, base)
    n = d[r]
    return conv(q, base) + n if q else n

for TEST in range(int(input())):
    num, base = map(int, input().split())
    r = conv(num, base)
    r2 = set()
    for c in r: r2.add(c)
    print("Base-%d representation of %d is %s; "%(base, num, r), end="")
    if len(r2)==base:
        print("contains all digits.")
    else:
        print("does not contain all digits.")
