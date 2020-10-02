from sys import stdin
def input(): return stdin.readline().rstrip()

T_raw = input().split(":")
T = int(T_raw[0])*60 + int(T_raw[1])

for i in range(120):
    if (T >= 420 and T < 600) or (T >= 900 and T < 1140):
        T += 2
    else:
        T += 1
    T %= 1440

h, m = 0, T
h += m // 60
m = m % 60
h %= 24

print("%02d:%02d"%(h,m))