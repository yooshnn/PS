import sys
input = sys.stdin.readline

res = 0

def cc(c):
    h, m = map(int, c.split(":"))
    return h*60 + m

recSet = set()

for TEST in range(int(input())):
    clock = input().rstrip()
    time = cc(clock)

    if time<6*60+30 or time>19*60: continue
    recSet.add(time)

rec = sorted([x for x in recSet])
if not rec:
    print(0)
    sys.exit(0)
if cc("6:30")<=rec[0]<=cc("10:00"):
    if cc("6:30")<=rec[-1]<=cc("16:00"):
        print(24000)
    elif cc("16:01")<=rec[-1]<=cc("19:00"):
        print(36000)
if cc("10:01")<=rec[0]<=cc("16:00"):
    if cc("10:01")<=rec[-1]<=cc("16:00"):
        print(16800)
    elif cc("16:01")<=rec[-1]<=cc("19:00"):
        print(24000)