ans = 0
for i in range(0,8):
    line = input()
    for j in range(0,4):
        if (line[j*2+(1 if i%2==1 else 0)] == 'F'):
            ans += 1
print(ans)