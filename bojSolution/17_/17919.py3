a = [x for x in input().split()]
cnt = 0
for w in a:
    for i in range(len(w)-1):
        if w[i] == 'a' and w[i+1] == 'e':
            cnt += 1
            break
print("dae ae ju traeligt va"if cnt >= len(a)*0.4 else"haer talar vi rikssvenska")