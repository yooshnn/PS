import sys; input = sys.stdin.readline

s=str(int(input())*int(input())*int(input()))
for i in range(10):
    print(s.count(str(i)))