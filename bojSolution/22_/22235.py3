import sys; input = sys.stdin.readline

def parseStation(e):
    return int(e[1:])
def parseTime(e):
    e = [*map(int, e.split(":"))]
    if len(e)==2:
        return 3600*e[0] + 60*e[1]
    return 3600*e[0] + 60*e[1] + e[2]
def intToTime(e):
    HH = e//3600
    e -= HH*3600
    mm = e//60
    e -= mm*60
    ss = e
    HH, mm, ss = str(HH), str(mm), str(ss)
    return (HH if len(HH)==2 else "0"+HH) + ":" + (mm if len(mm)==2 else "0"+mm) + ":" + (ss if len(ss)==2 else "0"+ss)

INF = 100000
delay = {210: 1, 221: 2, 225: 1, 245: 2, 249: 2, 256: 1, 220: 2, 222: 1, 238:1, 247: 3, 250: 1, 266: 1}

gahui_at = 225
glob_time = parseTime(input().rstrip())
line = []
earliest_arrival = [INF for i in range(273)]
earliest_arrival[225] = glob_time

for i in range(int(input())):
    u, v, w = input().split()
    line.append([parseStation(u), parseStation(v), parseTime(w), False, True])
line.sort(key=lambda x: (x[2], x[0]))

while glob_time < 86400:
    for elem in line:
        u, v, w, has_gahui, is_begin = elem
        if w > glob_time: continue
        if u == v: continue

        if not has_gahui:
            if earliest_arrival[u] < w + (0 if is_begin else 1):
                has_gahui = True
        if has_gahui:
            earliest_arrival[u+1] = min(earliest_arrival[u+1], w + 60 * (2 + (delay[u] if (u in delay) else 0)))
        w += 60 * (2 + (delay[u] if (u in delay) else 0)) + 20
        u += 1
        elem[0], elem[1], elem[2], elem[3], elem[4] = u, v, w, has_gahui, False

    glob_time += 1

if earliest_arrival[272] < 86400:
    print(intToTime(earliest_arrival[272]))
else:
    print(-1)