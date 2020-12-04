import sys
input = sys.stdin.readline

N = int(input())
s = [*map(int, input().split())]
f = input().rstrip()
r = 0

for c in s:
    r ^= c-2

if f=="Whiteking":
    print(["Whiteking", "Blackking"][r==0])
else:
    print(["Whiteking", "Blackking"][r!=0])