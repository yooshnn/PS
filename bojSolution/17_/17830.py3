import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    l, b = input().split()
    l = int(l)
    a = int("1"*l, 2)
    c = int(b.replace("?", "1"), 2)
    d = int(b.replace("?", "0"), 2)
    print(len(bin(a*c))-2, end=" ")
    print(len(bin(a*d))-2)