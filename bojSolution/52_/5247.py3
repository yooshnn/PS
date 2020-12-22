import sys; input = sys.stdin.readline

while 1:
    line = input().rstrip()
    if not line: break

    cnt = 0
    node = {}
    adj = []

    if line == "GRAPH BEGIN":
        while 1:
            line = input().rstrip()
            if line=="GRAPH END": break
            line = line.split()
            for n in line:
                try: node[n] += 0
                except:
                    node[n] = cnt; cnt += 1
                    adj.append(set())
            for i in range(1, len(line)):
                adj[node[line[0]]].add(node[line[i]])
                adj[node[line[i]]].add(node[line[0]])
        res0, res1 = cnt, 0
        for i in adj:
            res1 += len(i)
        print("NODES %d EDGES %d"%(res0, res1//2))
