from sys import stdin
def input(): return stdin.readline().rstrip()

a, e = int(input()), int(input())

Troy, Vlad, Graeme = True, True, True

if a<3 or e>4:
    Troy = False
if a>6 or e<2:
    Vlad = False
if a>2 or e>3:
    Graeme = False

if Troy: print("TroyMartian")
if Vlad: print("VladSaturnian")
if Graeme: print("GraemeMercurian")