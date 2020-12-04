import sys
import math
input = sys.stdin.readline

for TEST in range(int(input())):
    h, t = map(float, input().split())
    try:
        d = abs(h/math.tan(t*math.pi/180)-h)
        print("Case %d: %f"%(TEST+1, d))
    except:
        print("Case %d: %s"%(TEST+1, "Infinity"))
