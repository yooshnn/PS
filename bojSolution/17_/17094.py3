import sys; input = sys.stdin.readline

n = int(input())
a = input().count("e")
b = n-a

if a==b:
    print("yee")
elif a>b:
    print("e")
else:
    print(2)
