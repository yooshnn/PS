import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    t = "".join(input().split()).replace("O", "0").replace("I", "1")
    print("Case #%d: %s"%(TEST+1, "".join([chr(int(t[8*i:8*(i+1)], 2)) for i in range(n)])))