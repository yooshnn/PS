import sys; input = sys.stdin.readline
import math

N = input().rstrip()
res = 0

if int(N)<10: pass
elif int(N)<100: res = 9
else: res = int(str(len(N)-2) + "8"*(len(N)-2) + "9")

b = 1 if int(N)<10 else int("1"+"0"*(len(N)-1))
res += len(N) * (int(N)-b+1)

print(res)