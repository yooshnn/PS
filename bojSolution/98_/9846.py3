import sys; input = sys.stdin.readline
import graphlib

graph = {}
N, M = map(int, input().split())

for i in range(N):
    graph[i+1] = set()

for _ in range(M):
    s = input().rstrip().split(">")
    if s[0].find(",")==-1:
        s[0] = int(s[0])
        for i in [*map(int, s[1].split(","))]:
            graph[i].add(s[0])
    else:
        s[1] = int(s[1])
        for i in [*map(int, s[0].split(","))]:
            graph[s[1]].add(i)

try: print(*graphlib.TopologicalSorter(graph).static_order())
except: print(0)