import sys
input = sys.stdin.readline

d = {
"Kamen": 0, "Rock": 0, "Pierre": 0, "Stein": 0, "Ko": 0, "Koe": 0, "Sasso": 0, "Roccia": 0, "Guu": 0, "Kamien": 0, "Piedra": 0,
"Nuzky": 1, "Scissors": 1, "Ciseaux": 1, "Schere": 1, "Ollo": 1, "Olloo": 1, "Forbice": 1, "Choki": 1, "Nozyce": 1, "Tijera": 1,
"Papir": 2, "Paper": 2, "Feuille": 2, "Papier": 2, "Papir": 2, "Carta": 2, "Rete": 2, "Paa": 2, "Papier": 2, "Papel": 2
}

game = 0
go = True
while 1:
    game += 1
    if not go: break
    p1, p2 = input().split(), input().split()
    pp1, pp2 = 0, 0
    while 1:
        line = input().rstrip()
        if line=="-": break
        if line==".":
            go = False; break
        a, b = line.split()
        a, b = d[a], d[b]
        if a==0:
            if b==1: pp1 += 1
            elif b==2: pp2 += 1
        elif a==1:
            if b==0: pp2 += 1
            elif b==2: pp1 += 1
        else:
            if b==0: pp1 += 1
            elif b==1: pp2 += 1
    if game!=1: print()
    print("Game #%d:"%game)
    print("%s: %d point%s"%(p1[1], pp1, "" if pp1==1 else "s"))
    print("%s: %d point%s"%(p2[1], pp2, "" if pp2==1 else "s"))
    if pp1==pp2: print("TIED GAME")
    elif pp1>pp2: print("WINNER: %s"%p1[1])
    else: print("WINNER: %s"%p2[1])