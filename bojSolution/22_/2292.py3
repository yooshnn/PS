from sys import stdin
n = int(stdin.readline())

count = 1
circle = 6
while count < n:
    count += circle
    circle += 6
print(int(circle/6))