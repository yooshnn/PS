import sys
input = sys.stdin.readline

for restaurant in range(int(input())):
    menus = int(input())
    title = input().rstrip()
    peasoup, pancakes = False, False
    for menu in range(menus):
        req = input().rstrip()
        if req == "pea soup":
            peasoup = True
        if req == "pancakes":
            pancakes = True
    if peasoup and pancakes:
        print(title)
        sys.exit(0)
print("Anywhere is fine I guess")