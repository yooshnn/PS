from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    s=input().split()
    print(int(str(eval(s[0][::-1]+"+"+s[1][::-1]))[::-1]))