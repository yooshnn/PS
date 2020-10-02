score = [3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1];
field = [None]*200

line = input()
N = int(line.split(" ")[0])
M = int(line.split(" ")[1])
line = input()
A = line.split(" ")[0]
B = line.split(" ")[1]

if (N <= M) :
    cnt = 0
    for cha in A:
        field[cnt] = cha
        cnt += 2
    cnt = 1
    for cha in B:
        field[cnt] = cha
        cnt += 2 if field[cnt+1] != None else 1
    del field[cnt:]
else:
    cnt = 1
    for cha in B:
        field[cnt] = cha
        cnt += 2
    cnt = 0
    for cha in A:
        field[cnt] = cha
        cnt += 2 if field[cnt+1] != None else 1
    del field[cnt:]
    
cnt = 0
for cha in field:
    field[cnt] = score[ord(field[cnt])-65]
    cnt += 1

while (cnt > 2):
    cnt = 0
    for num in field[:-1]:
        field[cnt] += field[cnt+1]
        field[cnt] %= 10
        cnt += 1
    del field[cnt:]

print(str(field[0]*10 + field[1]) + "%")