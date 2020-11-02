import sys
input = sys.stdin.readline

n, k, r = int(input()), int(input()), 0

if 60+k >= n: print(n*1500)
else: print((60+k)*1500 + max(0, (n-(60+k))*3000))