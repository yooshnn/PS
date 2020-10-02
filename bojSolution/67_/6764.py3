from sys import stdin
def input(): return stdin.readline().rstrip()

fish = []
for i in range(4):
    fish.append(int(input()))

rising = True
diving = True
cons = True

for i in range(1,4):
    if fish[i-1] >= fish[i]:
        rising = False
    if fish[i-1] <= fish[i]:
        diving = False
    if fish[i-1] != fish[i]:
        cons = False

if rising:
    print("Fish Rising")
elif diving:
    print("Fish Diving")
elif cons:
    print("Fish At Constant Depth")
else:
    print("No Fish")