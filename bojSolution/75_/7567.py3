dish = input()
height = 10

for i in range(1,len(dish)):
    if dish[i] == dish[i-1]:
        height += 5
    else:
        height += 10

print(height)
