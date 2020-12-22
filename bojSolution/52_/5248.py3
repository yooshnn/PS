import sys; input = sys.stdin.readline
import collections

ff = True
while 1:
    if ff:
        ff = False
        line = input().rstrip()
        if not line: break

    cnt = 0
    node = {}
    idToNode = {}
    adj = []

    if line == "GRAPH BEGIN":
        while 1:
            line = input().rstrip()
            if line=="GRAPH END": break
            line = line.split()
            for n in line:
                try: node[n] += 0
                except:
                    node[n] = cnt; idToNode[cnt] = n; cnt += 1
                    adj.append(set())
            for i in range(1, len(line)):
                adj[node[line[0]]].add(node[line[i]])
                adj[node[line[i]]].add(node[line[0]])
        while 1:
            line = input().rstrip()
            if not line: sys.exit(0)
            if line=="GRAPH BEGIN": break

            res = []
            dup = [False for x in range(cnt)]; dup[node[line]] = True
            que = collections.deque()
            que.append((node[line], 0))
            while que:
                cur, tt = que.pop()
                if tt==2:
                    res.append(idToNode[cur]); continue
                for next in adj[cur]:
                    if not dup[next]:
                        dup[next] = True
                        que.append((next, tt+1))
            print(*sorted(res))
