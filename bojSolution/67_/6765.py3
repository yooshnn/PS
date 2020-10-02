from sys import stdin
def input(): return stdin.readline().rstrip()

scale = int(input())
icon = [["*","x","*"],[" ","x","x"],["*"," ","*"]]

for r in range(3):
    for sr in range(scale):
        for c in range(3):
            for sc in range(scale):
                print(icon[r][c], end="")
        print()