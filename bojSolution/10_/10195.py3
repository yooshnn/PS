import sys; input = sys.stdin.readline

TEST = int(input())
for tt in range(TEST):
    line = input().split()
    R, C = int(line[2]), int(line[4])
    stalagmite = [0 for x in range(C)]
    line = input().split()
    for __ in range(int(line[0])):
        line = input().split()
        stalagmite[int(line[3])] = int(line[0])
    print("Case: %d"%(tt+1))
    line = input().split()
    for __ in range(int(line[0])):
        seq = input().strip()
        r, c = 0, 0
        bad, crash1, crash2, crash3 = False, False, False, False
        for cur in seq:
            c += 1
            if cur=="^": r -= 1
            if cur=="v": r += 1
            if r==-1:
                bad = crash2 = True
            if r==R:
                bad = crash3 = True
            if stalagmite[c]>0 and r>=R-stalagmite[c]:
                bad = crash1 = True
            if bad: break
        print("Sequence %s "%seq, end="")
        if bad:
            if crash1: print("Crashed into stalagmite")
            elif crash2: print("Crashed into tunnel ceiling")
            else: print("Crashed into tunnel floor")
        else:
            print("Reached end of tunnel")
    if tt!=TEST-1: input()