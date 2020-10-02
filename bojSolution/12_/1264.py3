from sys import stdin
while True:
    s=stdin.readline()[:-1]
    if s=="#":
        break
    print(s.count("a")+s.count("i")+s.count("u")+s.count("e")+s.count("o")+s.count("A")+s.count("I")+s.count("U")+s.count("E")+s.count("O"))