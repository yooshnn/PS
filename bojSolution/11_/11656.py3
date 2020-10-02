from sys import stdin
from queue import PriorityQueue
def input(): return stdin.readline().rstrip()

s=input()
r=PriorityQueue()
for i in range(len(s)):
    r.put(s[i:])
while not r.empty():
    print(r.get())