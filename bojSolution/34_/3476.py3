from sys import stdin
def input(): return stdin.readline().rstrip()

class Statement:
    stmtCnt = 0
    contradiction = False

    def __init__(self, sub, pre, obj, pos):
        self.Subject = sub
        self.Plural = True if (sub == "I" or sub == "you") else False
        self.Predicate = pre
        self.Object = obj
        self.Positive = pos
        Statement.stmtCnt += 1

    def setSub(self, sub):
        self.Subject = sub
        self.Plural = True if (sub == "I" or sub == "you") else False
    def setPre(self, pre): self.Predicate = pre
    def setObj(self, obj): self.Object = obj
    def setPos(self, pos): self.Positive = pos

    def getSub(self): return self.Subject
    def getPre(self): return self.Predicate
    def getObj(self): return self.Object
    def getPos(self): return self.Positive
    def getPlu(self): return self.Plural

    def clear(self):
        self.setSub("")
        self.setPre("")
        self.setObj("")
        self.setPos(True)

Stmt = []

def convToInfinitive(pre, sub):
    if sub != "I" and sub != "you":
        return pre[:-1]
    return pre

def convFromInfinitive(pre, sub):
    if sub != "I" and sub != "you":
        return pre + "s"
    return pre


def doesSubjectPredicate(sub, pre, obj):
    for i in range(Statement.stmtCnt):
        if Stmt[i].getPre() != pre or Stmt[i].getObj() != obj: continue
        if Stmt[i].getSub() != "everybody" and Stmt[i].getSub() != sub: continue

        if sub == "I": sub = "you"
        elif sub == "you": sub = "I"

        if Stmt[i].getPos():
            pre = convFromInfinitive(pre, sub)
            print("yes, ",sub," ",pre,(" " + obj) if obj!="" else "",".",sep="")
        else:
            if sub != "I" and sub != "you":
                print("no, ",sub," doesn't ",pre,(" " + obj) if obj!="" else "",".",sep="")
            else:
                print("no, ",sub," don't ",pre,(" " + obj) if obj!="" else "",".",sep="")
        return
    print("maybe.")


def whatDoesSubjectDo(sub):
    whatC = 0
    whats=[]
    for i in range(Statement.stmtCnt):
        #print(Stmt[i].getSub())
        if Stmt[i].getSub() == sub or Stmt[i].getSub() == "everybody":
            ts = ""
            if not Stmt[i].getPos(): # don't doesn't
                ts += "don't " if (sub == "I" or sub == "you") else "doesn't "
            if (sub == "I" or sub == "you") or not Stmt[i].getPos(): ts += Stmt[i].getPre()
            else: ts += Stmt[i].getPre() + "s"
            ts += (" " + Stmt[i].getObj()) if Stmt[i].getObj() != "" else ""
            whats.append(ts)

    if len(whats)==0:
        print("I don't know.")
        return

    if sub == "I": sub = "you"
    elif sub == "you": sub = "I"

    print(sub,end=" ")
    for i in range(len(whats)):
        if i>0:
            if i < len(whats) - 1:
                print(", ",end="")
            else:
                print(", and ",end="")
        print(whats[i],end="")
    print(".")



def whoPredicates(pre, obj):
    thirdshape = True
    nobody = False
    subs=[]
    for i in range(Statement.stmtCnt):
        if Stmt[i].getPre() != pre or Stmt[i].getObj() != obj:
            continue
        if Stmt[i].getPos():
            if len(subs)>0 or Stmt[i].getSub() == "I" or Stmt[i].getSub() == "you":
                thirdshape = False
            if Stmt[i].getSub() == "everybody":
                del subs[:]
                subs.append("everybody")
                thirdshape = True
                break
            subs.append(Stmt[i].getSub())
        elif Stmt[i].getSub() == "everybody":
            nobody = True

    if len(subs) == 0:
        if nobody:
            print("nobody ",pre,"s",sep="",end="")
            if obj != "":
                print(" "+obj,end="")
            print(".")
        else:
            print("I don't know.")
        return
    else:
        for i in range(len(subs)):
            if i>0:
                print(" and " if i == len(subs)-1 else ", ",end="")
            if subs[i] == "you": print("I",end="")
            elif subs[i] == "I": print("you",end="")
            else: print(subs[i],end="")
        print(" ",pre,"s" if thirdshape else "",(" " + obj) if obj!="" else "",".",sep="")

def prepareStmt(sub, pre, obj, pos):
    for i in range(Statement.stmtCnt):
        if Stmt[i].getPre() != pre or Stmt[i].getObj() != obj: continue

        if sub == "everybody":
            if Stmt[i].getPos() != pos:
                Statement.contradiction = True
                return
            if Stmt[i].getSub() == "everybody":
                return
        elif Stmt[i].getSub() == sub or Stmt[i].getSub() == "everybody":
            if Stmt[i].getPos() != pos:
                Statement.contradiction = True
            return
    #print("updating stmt :",sub,pre,obj,"(",pos,")")
    Stmt.append(Statement(sub, pre, obj, pos))


def processQuestion(q):
    if Statement.contradiction:
        print("I am abroad.")
        return
    # does subject predicate [object] ?
    # who predicates [object] ?
    # what does subject do ?
    sub = ""; pre = ""; obj = ""
    qSplit = q.split()

    if qSplit[0] == "do" or qSplit[0] == "does":
        sub = qSplit[1]
        pre = qSplit[2]
        if len(qSplit) > 3:
            obj = " ".join(qSplit[3:])
        doesSubjectPredicate(sub, pre, obj)
    elif qSplit[0] == "who":
        pre = qSplit[1]
        pre = convToInfinitive(pre, "who")
        if len(qSplit) > 2:
            obj = " ".join(qSplit[2:])
        whoPredicates(pre, obj)
    else:
        sub = qSplit[2]
        whatDoesSubjectDo(sub)


def processStmt(q):
    sub = ""; pre = ""; obj = ""; pos = True
    if Statement.contradiction: return

    objPos = 2

    qSplit = q.split()
    sub, pre = qSplit[0], qSplit[1]
    if pre == "don't" or pre == "doesn't":
        pos = False
        pre = qSplit[2]
        objPos += 1
    else:
        pre = convToInfinitive(pre, sub)

    if sub == "nobody":
        pos = False
        sub = "everybody"

    if objPos < len(qSplit): obj = " ".join(qSplit[objPos:])

    prepareStmt(sub, pre, obj, pos)


def parseQuery(q):
    if q[-1] == ".":
        processStmt(q[:-1])
        return 0
    elif q[-1] == "?":
        print(q)
        processQuestion(q[:-1])
        return 1
    elif q[-1] == "!":
        print(q,end="")
        return 2


def run():
    Statement.contradiction = False
    Statement.stmtCnt = 0
    Stmt.clear()
    while True:
        query = input()
        if not query: break

        inputType = parseQuery(query)
        if inputType >= 1:
            print()
        if inputType == 2:
            break
    print()


# MAIN
Dialogue = int(input())
for i in range(1, Dialogue + 1):
    print("Dialogue #",i,":",sep="")
    run()
