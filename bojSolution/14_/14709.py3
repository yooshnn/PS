import sys
input = sys.stdin.readline

ac, ad, cd, good = False, False, False, True

for i in range(int(input())):
    a, b = map(int, input().split())
    if a>b:
        t = a; a = b; b = t
    if a==1 and b==3: ac = True
    if a==1 and b==4: ad = True
    if a==3 and b==4: cd = True
    if a==2 or b==2 or a==5 or b==5: good = False

print("Wa-pa-pa-pa-pa-pa-pow!" if ac and ad and cd and good else "Woof-meow-tweet-squeek")
