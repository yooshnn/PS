s=int(input())
for i in range(s,-1,-1):
    if i>2:
        print(i,"bottles of beer on the wall,",i,"bottles of beer.\nTake one down and pass it around,",i-1,"bottles of beer on the wall.")
    elif i==2:
        print(i,"bottles of beer on the wall,",i,"bottles of beer.\nTake one down and pass it around,",i-1,"bottle of beer on the wall.")
    elif i==1:
        print(i,"bottle of beer on the wall,",i,"bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.")
    else:
        if s>1:
            print("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more,",s,"bottles of beer on the wall.")
        else:
            print("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 1 bottle of beer on the wall.")
    if i!=0:
        print()
