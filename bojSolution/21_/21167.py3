import sys; input = sys.stdin.readline
import math

while 1:
    line = input()
    if not line: break
    r, s = line.split()
    r, s = int(r), float("0"+s)

    print(round(math.sqrt((r*(s+0.16))/0.067)))