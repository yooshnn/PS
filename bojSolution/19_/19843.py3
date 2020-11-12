import sys
input = sys.stdin.readline

T, N = map(int, input().split())
timeline = [1 for i in range(24*5)]

conv = {"Mon": 0, "Tue": 24, "Wed": 48, "Thu": 72, "Fri": 96}

for _ in range(N):
    line = input().split()
    for i in range(conv[line[0]] + int(line[1]), conv[line[2]] + int(line[3])):
        timeline[i] = 0;

res = T-(24*5-sum(timeline))

if res > 48:
    print(-1)
else:
    print(max(0, res))