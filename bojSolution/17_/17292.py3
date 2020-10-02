from sys import stdin
from queue import PriorityQueue
def input(): return stdin.readline().rstrip()

pq = PriorityQueue()
order = "123456789abcdef"
cards = input().split(",")

def od(s):
    return order.find(s)

for i in range(len(cards)-1):
    for j in range(i+1, len(cards)):
        name = cards[i]+cards[j]
        o = 0

        if abs(od(cards[i][0]) - od(cards[j][0])) == 1 or abs(od(cards[i][0]) - od(cards[j][0])) == 14:
            o = 100000000000000
        elif abs(od(cards[i][0]) - od(cards[j][0])) == 0:
            o = 100000000000

        if cards[i][1]==cards[j][1]: o += 1000000
        if od(cards[i][0]) > od(cards[j][0]):
            o += 10000 * od(cards[i][0])
            o += 100 * od(cards[j][0])
        else:
            o += 10000 * od(cards[j][0])
            o += 100 * od(cards[i][0])
        if cards[i][1] == "b" and cards[j][1] == "b":
            o += max(od(cards[i][0]), od(cards[j][0]))
        elif cards[i][1] == "b":
            o += od(cards[i][0])
        elif cards[j][1] == "b":
            o += od(cards[j][0])

        pq.put((-o, name))

while not pq.empty():
    print(pq.get()[1])
