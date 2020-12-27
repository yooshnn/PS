import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    t = bin(int(input()))[2:]
    print(1 if t[0]=="1" and t.count("1")==1 else 0)
