from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    err = [0]*6
    dance = input().split()
    if not dance: break
    if "dip" not in dance:
        err[5] = 1
    if dance[0] == "jiggle":
        err[4] = 1
    if "twirl" in dance and "hop" not in dance:
        err[3] = 1
    if len(dance) < 3: err[2] = 1
    else:
        if dance[-1]=="clap" and dance[-2]=="stomp" and dance[-3]=="clap": pass
        else: err[2] = 1
    for i in range(len(dance)):
        if dance[i] != "dip": continue
        if (i-1 >= 0 and dance[i-1]=="jiggle") or (i-2 >= 0 and dance[i-2]=="jiggle") or (i+1 < len(dance) and dance[i+1]=="twirl"): continue
        dance[i] = "DIP"
        err[1] = 1
    if sum(err) == 0:
        print("form ok:", " ".join(dance))
    elif sum(err) == 1:
        print("form error ", end="")
        for id, e in enumerate(err):
            if e==1: print(id, end=": ")
        print(" ".join(dance))
    elif sum(err) == 2:
        el = []
        for id, e in enumerate(err):
            if e==1: el.append(str(id))
        print("form errors ", " and ".join(el), ": ", " ".join(dance), sep="")
    else:
        el = []
        for id, e in enumerate(err):
            if e==1: el.append(str(id))
        print("form errors ", end="")
        print(", ".join(el[:len(el)-1]), end=" and ")
        print(el[-1], end=": ")
        print(" ".join(dance))