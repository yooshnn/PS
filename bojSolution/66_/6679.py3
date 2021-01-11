import sys; input = sys.stdin.readline

d = "0123456789ABCDEF"

def solve(num, base):
    q, r = divmod(num, base)
    n = d[r]
    return solve(q, base) + n if q else n

for i in range(1000, 10000):
    b10 = i
    b12 = solve(i, 12)
    b16 = solve(i, 16)
    a = sum(int(x) for x in str(b10))
    b = sum((int(x) if "0"<=x<="9" else 10+ord(x)-ord("A")) for x in str(b12))
    c = sum((int(x) if "0"<=x<="9" else 10+ord(x)-ord("A")) for x in str(b16))
    if a==b and b==c:
        print(b10)
