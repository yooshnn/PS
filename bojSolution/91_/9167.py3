import sys
input = sys.stdin.readline

#ff = open("output.txt", mode="w")

botWake = False
firstCall = 0
taunts = 0
li = []
def speak(s):
    global firstCall

    if firstCall:
        s = s[0].upper() + s[1:]
        firstCall -= 1
    li.append(s)
def shout():
    #ff.write(" ".join(li) + ".\n")
    print(" ".join(li), end=".\n")
    li.clear()

callCnt = [0 for i in range(15)]

def robot(s_):
    global taunts, botWake

    if botWake:
        print()
    else:
        botWake = True
    s = s_.split()
    #print("taunts left:", taunts)
    #ff.write("Knight: "+ " ".join(s)+"\n")
    print("Knight:", " ".join(s))
    wc = 0
    for ss in s:
        if any(c.isalpha() for c in ss):
            wc += 1

    ptr, id, holy = 0, 0, False
    trigger = "theholygrail"
    while ptr<len(s_) and ptr!=-1:
        ptr = s_[ptr:].find(trigger[id])
        id += 1
        if id==12:
            holy = True
            break

    if holy:
        speak("Taunter:")
        taunt(holy)
        shout()

    taunts = wc//3 - holy + (wc%3 != 0)
    while taunts > 0:
        speak("Taunter:")
        taunt(0)
        shout()


def taunt(holy):
    global callCnt, taunts, firstCall

    firstCall += 1

    if holy:
        gesture()
        return
    if taunts>0:
        taunts -= 1

    turn = callCnt[0]%4; callCnt[0] += 1

    if turn==0:
        sentence()
    elif turn==1:
        taunt(0)
        sentence()
    elif turn==2:
        noun(1)
    else:
        sentence()

def gesture():
    speak("(A childish hand gesture)")

def sentence():
    global callCnt
    turn = callCnt[1]%3; callCnt[1] += 1

    if turn==0:
        pastrel(); nounphrase()
    elif turn==1:
        presentrel(); nounphrase()
    else:
        pastrel(); article(); noun(0)

def nounphrase():
    article(); modifiednoun()

def modifiednoun():
    global callCnt
    turn = callCnt[3]%2; callCnt[3] += 1

    if turn==0: noun(0)
    else: modifier(); noun(0)

def modifier():
    global callCnt
    turn = callCnt[4]%2; callCnt[4] += 1

    if turn==0: adjective()
    else: adverb(); adjective()

def presentrel():
    speak("your"); presentperson(); presentverb()

def pastrel():
    speak("your"); pastperson(); pastverb()

def presentperson():
    global callCnt
    turn = callCnt[7]%3; callCnt[7] += 1

    speak(["steed", "king", "first-born"][turn])

def pastperson():
    global callCnt
    turn = callCnt[8]%5; callCnt[8] += 1

    speak(["mother", "father", "grandmother", "grandfather", "godfather"][turn])

def noun(ex):
    global callCnt
    turn = callCnt[9]%11; callCnt[9] += 1

    speak(["hamster", "coconut", "duck", "herring", "newt", "peril", "chicken", "vole", "parrot", "mouse", "twit"][turn] + ("!" if ex else ""))

def presentverb():
    global callCnt
    turn = callCnt[10]%2; callCnt[10] += 1

    speak(["is", "masquerades as"][turn])

def pastverb():
    global callCnt
    turn = callCnt[11]%2; callCnt[11] += 1

    speak(["was", "personified"][turn])

def article():
    speak("a")

def adjective():
    global callCnt
    turn = callCnt[13]%7; callCnt[13] += 1

    speak(["silly", "wicked", "sordid", "naughty", "repulsive", "malodorous", "ill-tempered"][turn])

def adverb():
    global callCnt
    turn = callCnt[14]%5; callCnt[14] += 1

    speak(["conspicuously", "categorically", "positively", "cruelly", "incontrovertibly"][turn])

while 1:
    line = input().rstrip()
    if not line: break
    robot(line)
