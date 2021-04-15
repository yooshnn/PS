import sys; input = sys.stdin.readline
import collections

class Fire:
    pid = 1
    record, count = dict(), collections.deque()

    def __init__(self, Action, Rules):
        self.action = Action
        self.rules = [i for i in Rules]
    def ask(self, Ip, Port):
        conditionMet = True
        for rule in self.rules:
            type, val = rule
            if type == "ip":
                if Ip != val: conditionMet = False
            if type == "port":
                if Port != val: conditionMet = False
            if type == "limit":
                if Fire.record[Ip] < int(val): conditionMet = False
        if conditionMet:
            if self.action == "accept":
                print("accept %d"%Fire.pid)
                Fire.pid += 1
                return True
            if self.action == "drop":
                print("drop %d"%Fire.pid)
                Fire.pid += 1
                return True
            if self.action == "log":
                print("log %d"%Fire.pid)
        return False


N = int(input())
rules = []
for _ in range(N):
    temp = input().split()
    action = temp[0]
    rules.append(Fire(action, [i.split("=") for i in temp[1:]]))

P = int(input())
for _ in range(P):
    ip, port = input().rstrip().split(":")

    if len(Fire.count)==1000: Fire.record[Fire.count.popleft()] -= 1
    Fire.count.append(ip)
    if ip in Fire.record: Fire.record[ip] += 1
    else: Fire.record[ip] = 1

    for i in range(N):
        if rules[i].ask(ip, port): break